#!/bin/sh

PATH=/bin:/usr/bin:/usr/pkg/bin

WRKSRC=$PWD
TARGET=$1
DISTFILES=$2

HOME="${WRKSRC}" XDG_CACHE_HOME="${WRKSRC}/.ecache" \
YARN_GLOBAL_FOLDER="${WRKSRC}/.ecache/yarn-global" \
YARN_CACHE_FOLDER="${WRKSRC}/${TARGET}" \
YARN_ENABLE_GLOBAL_CACHE=false \
YARN_ENABLE_TELEMETRY=0 \
YARN_ENABLE_SCRIPTS=false \
yarn install --immutable --mode=skip-build

mtree -cbnSp "${TARGET}" | mtree -C | sed \
        -e 's:time=[0-9.]*:time=61171200.000000000:' \
        -e 's:\([gu]id\)=[0-9]*:\1=0:g' \
        -e 's:mode=\([0-9]\)7[0-9][0-9]:mode=\1755:' \
        -e 's:mode=\([0-9]\)6[0-9][0-9]:mode=\1644:' \
        -e 's:flags=.*:flags=none:' \
        -e "s:^\.:./${TARGET}:" > "${TARGET}.mtree"

tar -cf - "@${TARGET}.mtree" | gzip -9n > "${DISTFILES}/${TARGET}.tar.gz"

sha512 "${DISTFILES}/${TARGET}.tar.gz"
stat -f 'Size (%N) = %z bytes' "${DISTFILES}/${TARGET}.tar.gz"

