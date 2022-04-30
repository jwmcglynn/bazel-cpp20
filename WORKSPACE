load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Use absl at head.
git_repository(
    name = "com_google_absl",
    branch = "master",
    remote = "https://github.com/abseil/abseil-cpp",
)

##
## gtest and dependencies, based on the contents of googletest/WORKSPACE
##
git_repository(
    name = "com_google_gtest",
    commit = "8ded48c37be09d8cc3665af1b414c5d53c0862e7",  # Latest as of 2022-05-01
    remote = "https://github.com/google/googletest",
)

# Note this must use a commit from the `abseil` branch of the RE2 project.
# https://github.com/google/re2/tree/abseil
http_archive(
    name = "com_googlesource_code_re2",
    sha256 = "906d0df8ff48f8d3a00a808827f009a840190f404559f649cb8e4d7143255ef9",
    strip_prefix = "re2-a276a8c738735a0fe45a6ee590fe2df69bcf4502",
    urls = ["https://github.com/google/re2/archive/a276a8c738735a0fe45a6ee590fe2df69bcf4502.zip"],  # 2022-04-08
)

git_repository(
    name = "bazel_skylib",
    remote = "https://github.com/bazelbuild/bazel-skylib",
    tag = "1.2.1",  # Latest as of 2022-05-01
)
