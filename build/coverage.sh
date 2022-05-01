#!/bin/bash -e
# Change current directory to the bazel workspace root.
cd "$(dirname "$(realpath "${BASH_SOURCE[0]}")")/.."

if [ ! `which java` ]; then
  echo "Error: Java is not installed."
  exit 1
fi

if [ ! `which genhtml` ]; then
  echo "Error: Could not find genhtml, is lcov installed?"
  exit 1
fi

JAVA_HOME=$(dirname $(dirname $(which java)))

bazel coverage -s \
    --local_test_jobs=1 \
    --nocache_test_results \
    //...

genhtml bazel-out/_coverage/_coverage_report.dat \
    --highlight \
    --legend \
    --output-directory coverage-report

echo ""
echo "Report saved to coverage-report/index.html"

if [ -n `which python3` ]; then
  echo "Starting webserver, Ctrl-C to exit..."
  python3 -m http.server --directory coverage-report
else
  echo "Not starting webserver, python3 is not installed."
fi
