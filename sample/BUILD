load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
load("//build:rules.bzl", "cc_fuzzer")

cc_library(
    name = "sample",
    srcs = [
        "sample.cc",
    ],
    hdrs = [
        "sample.h",
    ],
)

cc_test(
    name = "sample_tests",
    srcs = [
        "tests/sample_tests.cc",
    ],
    deps = [
        ":sample",
        "@com_google_gtest//:gtest_main",
    ],
)

cc_fuzzer(
    name = "sample_fuzzer",
    srcs = [
        "tests/sample_fuzzer.cc",
    ],
    corpus = "tests/sample_corpus",
    deps = [
        ":sample",
    ],
)
