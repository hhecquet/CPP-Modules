/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:26:05 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 19:26:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors and destructor
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Load exchange rate database from CSV file
void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    // Skip header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        parseDatabaseLine(line);
    }

    file.close();
}

// Process the input file
void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    // Skip header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        processInputLine(line);
    }

    file.close();
}

// Parse a line from the database CSV
void BitcoinExchange::parseDatabaseLine(const std::string& line) {
    std::istringstream iss(line);
    std::string date;
    std::string rateStr;
    
    if (std::getline(iss, date, ',') && std::getline(iss, rateStr)) {
        // Validate date format
        if (!isValidDate(date)) {
            return; // Skip invalid dates
        }
        
        // Convert rate to float
        float rate = std::atof(rateStr.c_str());
        
        // Store in database
        _database[date] = rate;
    }
}

// Process a line from the input file
void BitcoinExchange::processInputLine(const std::string& line) {
    std::istringstream iss(line);
    std::string date;
    std::string valueStr;
    
    // Split by pipe character
    if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
        // Trim whitespace
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
        
        // Validate date
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            return;
        }
        
        // Convert and validate value
        char* endptr;
        float value = std::strtof(valueStr.c_str(), &endptr);
        
        // Check for conversion errors
        if (*endptr != '\0') {
            std::cout << "Error: not a valid number." << std::endl;
            return;
        }
        
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            return;
        }
        
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            return;
        }
        
        // Find appropriate exchange rate
        std::string closestDate = findClosestDate(date);
        if (closestDate.empty()) {
            std::cout << "Error: no exchange rate data available for this date." << std::endl;
            return;
        }
        
        // Calculate and output result
        float result = value * _database[closestDate];
        std::cout << date << " => " << value << " = " << result << std::endl;
    } else {
        std::cout << "Error: bad input => " << line << std::endl;
    }
}

// Validate date format (YYYY-MM-DD)
bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10)
        return false;
    
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue; // Skip hyphens
        if (!isdigit(date[i]))
            return false;
    }
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    // Basic validation
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    
    // More precise validation for days in month
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    } else if (month == 2) {
        // February: check for leap year
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28)) return false;
    }
    
    return true;
}

// Validate value (0-1000)
bool BitcoinExchange::isValidValue(const float value) const {
    return (value >= 0 && value <= 1000);
}

// Find the closest date (or the exact date) in the database
std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    // If exact date exists, return it
    std::map<std::string, float>::const_iterator it = _database.find(date);
    if (it != _database.end()) {
        return date;
    }
    
    // Otherwise, find the closest previous date
    it = _database.lower_bound(date);
    
    // If the date is earlier than any in the database
    if (it == _database.begin() && date < it->first) {
        return ""; // No valid date
    }
    
    // If we found a date that's later, go back one
    if (it == _database.end() || date < it->first) {
        if (it != _database.begin()) {
            --it;
            return it->first;
        }
        return ""; // No valid date
    }
    
    return it->first;
}