load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

##
## Toolchain
##
git_repository(
    name = "com_grailbio_bazel_toolchain",
    commit = "9e71d562023dc7994e747110ee1ca345ad6b4413", # Latest as of 2022-05-01
    remote = "https://github.com/grailbio/bazel-toolchain.git",
)

load("@com_grailbio_bazel_toolchain//toolchain:deps.bzl", "bazel_toolchain_dependencies")

bazel_toolchain_dependencies()

load("@com_grailbio_bazel_toolchain//toolchain:rules.bzl", "llvm_toolchain")

llvm_toolchain(
    name = "llvm_toolchain",
    llvm_version = "14.0.0",
    stdlib = {
        "linux-x86_64": "builtin-libc++",
        "linux-aarch64": "builtin-libc++",
    },
)

load("@llvm_toolchain//:toolchains.bzl", "llvm_register_toolchains")

llvm_register_toolchains()

##
## absl, use at head since it is stable and follows the library's guidelines
##
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
