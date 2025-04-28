/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:48:34 by hhecquet          #+#    #+#             */
/*   Updated: 2025/04/28 14:13:08 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(char **argv, int argc)
{
	if (argc != 4)
		return (0);
	myfile.open ()
}


Here’s a roadmap for building your “find-and-replace” utility in C++, using only std::string member functions (but not std::string::replace) and <fstream> for file I/O:

1. Parse and validate command-line arguments
Your main should accept argc, argv.

Immediately check that argc == 4. If not, print a usage message and return non-zero:

cpp
Copy
Edit
if (argc != 4) {
    std::cerr << "Usage: " << argv[0]
              << " <filename> <s1> <s2>\n";
    return 1;
}
std::string filename = argv[1];
std::string s1       = argv[2];
std::string s2       = argv[3];
// edge-case: empty s1?
if (s1.empty()) {
    std::cerr << "Error: s1 must be non-empty\n";
    return 1;
}
2. Open the input file for reading
Use std::ifstream:

cpp
Copy
Edit
std::ifstream infile{ filename };
if (!infile) {
    std::cerr << "Error: cannot open input file “" << filename << "”\n";
    return 1;
}
3. Prepare the output file
Append the literal ".replace" to your input name:

cpp
Copy
Edit
std::string outname = filename + ".replace";
std::ofstream outfile{ outname };
if (!outfile) {
    std::cerr << "Error: cannot open output file “" << outname << "”\n";
    return 1;
}
On C++11 and later, the {} constructor takes a std::string directly; no need for .c_str().

4. Read & process the input
You have two common strategies:

Line by line (preserves line breaks exactly).

Whole file at once (simpler code, but more memory).

(a) Line-by-line
cpp
Copy
Edit
std::string line;
while (std::getline(infile, line)) {
    // perform find-and-replace on `line`
    … 
    outfile << line << '\n';
}
(b) Whole-file
cpp
Copy
Edit
// slurp entire file into `content`
std::string content{
    std::istreambuf_iterator<char>(infile),
    std::istreambuf_iterator<char>()
};
// then process content once and write it out:
std::string result = replaceAll(content, s1, s2);
outfile << result;
5. Implement replaceAll() without std::string::replace()
Here’s one pattern using find(), substr() and append():

cpp
Copy
Edit
std::string replaceAll(
    const std::string &haystack,
    const std::string &needle,
    const std::string &replacement)
{
    std::string result;
    std::size_t pos = 0;  // current scan position
    while (true) {
        // find next occurrence
        std::size_t found = haystack.find(needle, pos);
        if (found == std::string::npos) {
            // append the tail, then break
            result.append(haystack.substr(pos));
            break;
        }
        // 1) append the chunk before the match
        result.append(haystack.substr(pos, found - pos));
        // 2) append the replacement
        result.append(replacement);
        // 3) move past the matched needle
        pos = found + needle.size();
    }
    return result;
}
Why this works:

find(needle, pos) locates each non-overlapping occurrence of needle.

substr(pos, found-pos) copies the “unchanged” portion.

You never call std::string::replace()—just find(), substr(), and append().

6. Wire it all together
A sketch of main():

cpp
Copy
Edit
int main(int argc, char** argv) {
    // 1) args + validation
    if (argc != 4) { … }

    std::string filename = argv[1], s1 = argv[2], s2 = argv[3];
    if (s1.empty()) { … }

    // 2) open files
    std::ifstream infile{ filename };
    if (!infile) { … }
    std::ofstream outfile{ filename + ".replace" };
    if (!outfile) { … }

    // 3) read whole file and transform
    std::string content{
        std::istreambuf_iterator<char>(infile),
        std::istreambuf_iterator<char>()
    };
    std::string transformed = replaceAll(content, s1, s2);

    // 4) write out and exit
    outfile << transformed;
    return 0;
}
—or, if you prefer line-wise processing, do the loop over std::getline() and call replaceAll(line, s1, s2) on each line individually, writing '\n' after.

7. Error-handling & edge cases
Empty s1: must be rejected, since “find empty string” loops infinitely.

File I/O failures: check your streams after opening.

Huge files: if you read the whole file at once, be aware of memory usage. Line-by-line is more streaming-friendly.

Overlapping patterns: this algorithm will replace non-overlapping occurrences (e.g. searching for "aba" in "ababa" yields one match at position 0; then resumes at 0+3=3).

8. Testing
Create small test files and run:

bash
Copy
Edit
# 1. no matches
echo "hello world" > f1.txt
./replace f1.txt foo bar
# check that f1.txt.replace == "hello world"

# 2. single match
echo "foo baz" > f2.txt
./replace f2.txt foo bar
# expect "bar baz"

# 3. multiple matches
echo "foo foo foo" > f3.txt
./replace f3.txt foo x
# expect "x x x"

# 4. overlapping edge
echo "abababa" > f4.txt
./replace f4.txt aba z
# find non-overlapping: transforms to "zba", not "zzba" or something weird.

# 5. very large file (you can generate with `seq` or repeat a line, to check speed)
Automate these with a shell script or a simple Python harness. Verify both stdout and exit codes.

With that plan in hand, you’ll have a solid, correct solution that:

Uses only <fstream> and std::string methods (minus replace).

Handles errors and bad input gracefully.

Is easy to read, test, and maintain.

Happy coding!