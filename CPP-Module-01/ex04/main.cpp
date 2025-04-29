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

std::string replaceAll(const std::string &line, const std::string &to_search, const std::string &replace)//why const
{
	std::string result;
	std::size_t pos = 0;
	while (true)
	{
		std::size_t found = line.find(to_search, pos);
		if (found == std::string::npos)
		{
			result.append(line.substr(pos));
			break;
		}
		result.append(line.substr(pos, found - pos));
		result.append(replace);
		pos = found + to_search.size();
	}
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	std::string filename = argv[1], s1 = argv[2], s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "s1 cannot be empty\n";
		return 1;
	}
	std::ifstream infile{filename};
	if (!infile)
	{
		std::cerr << "cannot open \""<< filename << "\"\n";
		return 1;
	}
	std::string outname = filename + ".replace";
	std::ofstream outfile{outname};
	std::string content
	{
		std::istreambuf_iterator<char>(infile),
		std::istreambuf_iterator<char>()
	};
	std::string transformed = replaceAll(content, s1, s2);
	outfile << transformed;
    return 0;
}

// std::string is like a note in your hand.
// std::ifstream is like opening a drawer to read the note.
// std::ofstream is like writing a new note and putting it back into the drawer.