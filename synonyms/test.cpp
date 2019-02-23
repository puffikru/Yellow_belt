#include "test.h"
#include "synonyms.h"

void TestAddSynonyms() {
    {
        Synonyms empty;
        AddSynonyms(empty, "a", "b");
        const Synonyms expected = {
            {"a", {"b"}},
            {"b", {"a"}}
        };
        AssertEqual(empty, expected, "Add to empty");
    }
    {
        Synonyms synonyms = {
            {"a", {"b"}},
            {"b", {"a", "c"}},
            {"c", {"b"}}
        };
        AddSynonyms(synonyms, "a", "c");
        const Synonyms expected = {
            {"a", {"b", "c"}},
            {"b", {"a", "c"}},
            {"c", {"b", "a"}}
        };
        AssertEqual(synonyms, expected, "Add to non empty");
    }
}


void TestCount() {
    {
        Synonyms empty;
        AssertEqual(GetSynonymsCount(empty, "a"), 0u, "empty a");
    }
    {
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };
        AssertEqual(GetSynonymsCount(synonyms, "a"), 2, "synonyms a");
        AssertEqual(GetSynonymsCount(synonyms, "b"), 1, "synonyms b");
        AssertEqual(GetSynonymsCount(synonyms, "z"), 0, "synonyms z");
    }
}


void TestAreSynonyms() {
    {
        Synonyms empty;
        Assert(!AreSynonyms(empty, "a", "b"), "empty a b");
        Assert(!AreSynonyms(empty, "b", "a"), "empty b a");
    }
    {
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a", "c"}},
            {"c", {"a", "b"}}
        };
        Assert(AreSynonyms(synonyms, "a", "b"), "synonyms a b");
        Assert(AreSynonyms(synonyms, "b", "a"), "synonyms b a");
        Assert(AreSynonyms(synonyms, "a", "c"), "synonyms a c");
        Assert(AreSynonyms(synonyms, "c", "a"), "synonyms c a");
        Assert(AreSynonyms(synonyms, "b", "c"), "synonyms b c");
        Assert(AreSynonyms(synonyms, "c", "b"), "synonyms c b");
    }
}


void TestAll() {
    TestRunner tr;
    tr.RunTest(TestAreSynonyms, "TestAreSynonyms");
    tr.RunTest(TestCount, "TestCount");
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
}