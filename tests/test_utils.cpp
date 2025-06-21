#include "doctest/doctest.h"
#include "utils/timer.h"
#include "utils/config.h"
#include "utils/filesystem.h"

using namespace huzlip::utils;

TEST_CASE("Timer measures elapsed time") {
    Timer t;
    CHECK(t.elapsed() >= 0);
}

TEST_CASE("Config stores and retrieves values") {
    Config cfg;
    cfg.set("foo", "bar");
    CHECK(cfg.get("foo") == "bar");
    CHECK(cfg.contains("foo"));
    CHECK(cfg.get("missing", "def") == "def");
}

TEST_CASE("Filesystem detects file existence") {
    std::string fname = "test_utils_tmp.txt";
    Filesystem::writeFile(fname, "abc");
    CHECK(Filesystem::exists(fname));
    CHECK(Filesystem::readFile(fname) == "abc");
    remove(fname.c_str());
}