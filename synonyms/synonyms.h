#ifndef YELLOW_SYNONYMS_H
#define YELLOW_SYNONYMS_H
#pragma once
#include <map>
#include <set>
#include <string>

using Synonyms = std::map<std::string, std::set<std::string> >;

void AddSynonyms(Synonyms& synonyms,
                 const std::string& first_word, const std::string& second_word);
size_t GetSynonymsCount(Synonyms& synonyms, const std::string& first_word);
bool AreSynonyms(Synonyms& synonyms,
                 const std::string& first_word, const std::string& second_word);

#endif //YELLOW_SYNONYMS_H
