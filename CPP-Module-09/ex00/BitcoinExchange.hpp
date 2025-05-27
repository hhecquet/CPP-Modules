/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:26:05 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 09:42:53 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <stdexcept>
#include <limits>
#include <algorithm>

class BitcoinExchange {
private:
    std::map<std::string, float> _database;

    bool isValidDate(const std::string& date) const;
    bool isValidValue(const float value) const;
    std::string findClosestDate(const std::string& date) const;
    void parseDatabaseLine(const std::string& line);
    void processInputLine(const std::string& line);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);
};