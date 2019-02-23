#include "synonyms.h"

void AddSynonyms(Synonyms& synonyms,
                 const std::string& first_word, const std::string& second_word) {
    synonyms[second_word].insert(first_word);
    synonyms[first_word].insert(second_word);
}

size_t GetSynonymsCount(Synonyms& synonyms, const std::string& first_word) {
    return synonyms[first_word].size();
}


bool AreSynonyms(Synonyms& synonyms,
                 const std::string& first_word, const std::string& second_word) {
    return synonyms[first_word].count(second_word) == 1;
}
