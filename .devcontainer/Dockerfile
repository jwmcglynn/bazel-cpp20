# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.231.6/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version (use Debian 11, Ubuntu 18.04/21.04 on local arm64/Apple Silicon): debian-11, debian-10, ubuntu-21.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="ubuntu-21.04"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

#
# Install LLVM dependencies
#
RUN apt-get update \
    && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends software-properties-common

#
# Install LLVM
#
RUN mkdir -p /tmp/llvm \
    && cd /tmp/llvm \
    && wget https://apt.llvm.org/llvm.sh \
    && chmod +x ./llvm.sh \
    && ./llvm.sh 10 \
    && rm -rf /tmp/llvm

# Install libc++
RUN apt-get update \
    && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends libc++-10-dev libc++abi-10-dev

# Update path so this clang is first.
ENV PATH=/usr/lib/llvm-10/bin:${PATH}

#
# Install bazelisk
#
RUN if [[ `dpkg --print-architecture` == "arm64" ]]; then \
        wget https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-arm64 -O /usr/local/bin/bazel \
        && chmod +x /usr/local/bin/bazel; \
    else \
        wget https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64 -O /usr/local/bin/bazel \
        && chmod +x /usr/local/bin/bazel; \
    fi

#
# Install buildifier
#
RUN if [[ `dpkg --print-architecture` == "arm64" ]]; then \
        wget https://github.com/bazelbuild/buildtools/releases/latest/download/buildifier-linux-arm64 -O /usr/local/bin/buildifier \
        && chmod +x /usr/local/bin/buildifier; \
    else \
        wget https://github.com/bazelbuild/buildtools/releases/latest/download/buildifier-linux-amd64 -O /usr/local/bin/buildifier \
        && chmod +x /usr/local/bin/buildifier; \
    fi
