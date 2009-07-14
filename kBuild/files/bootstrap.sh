# $NetBSD: bootstrap.sh,v 1.1.1.1 2009/07/14 19:25:05 tnn2 Exp $

set -e

# load environment
export $(kBuild/env.sh --full --eval --set)

# bootstrap kmk
cd ${WRKSRC}/src/kmk
autoreconf -if
rm -rf ${WRKSRC}/src/kmk/obj
mkdir ${WRKSRC}/src/kmk/obj
cd ${WRKSRC}/src/kmk/obj
../configure
cp config.h ../config.h.${KBUILD_TARGET}
make
cp kmk ${KBUILD_BIN_PATH}
cp kmk_redirect ${KBUILD_BIN_PATH}
rm -rf obj

# bootstrap ash
cd ${WRKSRC}/src/ash
${KBUILD_BIN_PATH}/kmk
rm -f ${KBUILD_BIN_PATH}/kmk_ash
cp ${WRKSRC}/out/${KBUILD_TARGET}.${KBUILD_TARGET_ARCH}/${KBUILD_TYPE}/kBuild/bin/${KBUILD_TARGET}.${KBUILD_TARGET_ARCH}/kmk_ash ${KBUILD_BIN_PATH}/kmk_ash

# bootstrap sed
cd ${WRKSRC}/src/sed
./configure --disable-nls
mv config.h config.h.${KBUILD_TARGET}
${KBUILD_BIN_PATH}/kmk
cp ${WRKSRC}/out/${KBUILD_TARGET}.${KBUILD_TARGET_ARCH}/${KBUILD_TYPE}/kBuild/bin/${KBUILD_TARGET}.${KBUILD_TARGET_ARCH}/kmk_sed ${KBUILD_BIN_PATH}/kmk_sed

# bootstrap lib
cd ${WRKSRC}/src/lib
${KBUILD_BIN_PATH}/kmk

# bootstrap kDepPre
cd ${WRKSRC}/src/kDepPre
${KBUILD_BIN_PATH}/kmk
cp ${WRKSRC}/out/${KBUILD_TARGET}.${KBUILD_TARGET_ARCH}/${KBUILD_TYPE}/kBuild/bin/${KBUILD_TARGET}.${KBUILD_TARGET_ARCH}/kDepPre ${KBUILD_BIN_PATH}/kDepPre

