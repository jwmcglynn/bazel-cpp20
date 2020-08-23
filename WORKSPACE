load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_google_gtest",
    remote = "https://github.com/google/googletest",
    tag = "release-1.10.0",
)

# Use absl at head.
git_repository(
    name = "com_google_absl",
    branch = "master",
    remote = "https://github.com/abseil/abseil-cpp",
)
