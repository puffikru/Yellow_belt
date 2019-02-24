



//void TestRealRootCount() {
//    mt19937 gen;
//    uniform_real_distribution<> unif(-10, 10);
//
//    for (auto i = 0; i < 100; ++i) {
//        const auto a = unif(gen);
//        const auto b = unif(gen);
//        const auto c = unif(gen);
//
//        int count = GetDistinctRealRootCount(a, b, c);
//
//        Assert(count >= 0 && count <= 2, "TestRealRoot");
//    }
//}