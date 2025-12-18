#!/usr/bin/env bash

# simple build script
# use:
# $ ./volksbuild.sh <optional argument of parallel workers>

set -e

# Optional argument: number of parallel workers
PARALLEL_ARGS=""
if [ $# -ge 1 ]; then
    PARALLEL_ARGS="--parallel-workers $1"
fi

colcon build \
    --packages-select sick_scan_xd \
    --cmake-args " -DROS_VERSION=2" " -DLDMRS=0" " -DSCANSEGMENT_XD=0" \
    --event-handlers console_direct+ \
    ${PARALLEL_ARGS}

source ./install/setup.bash

colcon build \
    --packages-ignore sick_scan_xd \
    ${PARALLEL_ARGS}