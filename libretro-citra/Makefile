# $NetBSD$

PKGNAME=	libretro-citra-20180519
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/citra/
COMMENT=	Libretro core based on the Citra Nintendo 3DS emulator
LICENSE=	gnu-gpl-v2

CITRA_TAG=	85e47f1ea7013eb9a0f27ec4b946d71e04f970c1
BOOST_TAG=	7310c95e2320ed262b0600315fa2f762c4b6cc54
CATCH_TAG=	62dae592c330ab74cea30c897255ee9518639c3f
CRYPTOPP_TAG=	5be140bcea453a00f7f2fec09fb9e37849d65d98
DYNARMIC_TAG=	d1d4705364031512cb89333aebc00b8d75a2f732
ENET_TAG=	39a72ab1990014eb399cee9d538fd529df99c6a0
FMT_TAG=	5859e58ba17073cf1c16536205450528f3530df0
INIH_TAG=	56edbbbef9ba432521442ee47ba7d1c8de37e63d
LIBRESSL_TAG=	cbb1dcab9a566d0aa0036339f21f2e37012b2507
NIHSTRO_TAG=	fd69de1a1b960ec296cc67d32257b0f9e2d89ac6
SOUNDTOUCH_TAG=	019d2089bbadf70d73ba85aa8ea51490b071262c
XBYAK_TAG=	c5da3778e7f84013fe8c26fcf18a67881bd1e825

DISTFILES+=	${CITRA_TAG}.tar.gz
DISTFILES+=	${BOOST_TAG}.tar.gz
DISTFILES+=	${CATCH_TAG}.tar.gz
DISTFILES+=	${CRYPTOPP_TAG}.tar.gz
DISTFILES+=	${DYNARMIC_TAG}.tar.gz
DISTFILES+=	${ENET_TAG}.tar.gz
DISTFILES+=	${FMT_TAG}.tar.gz
DISTFILES+=	${INIH_TAG}.tar.gz
DISTFILES+=	${LIBRESSL_TAG}.tar.gz
DISTFILES+=	${NIHSTRO_TAG}.tar.gz
DISTFILES+=	${SOUNDTOUCH_TAG}.tar.gz
DISTFILES+=	${XBYAK_TAG}.tar.gz

SITES.${CITRA_TAG}.tar.gz= \
    ${MASTER_SITE_GITHUB:=libretro/citra/archive/}

SITES.${BOOST_TAG}.tar.gz= \
    ${MASTER_SITE_GITHUB:=citra-emu/ext-boost/archive/}

SITES.${CATCH_TAG}.tar.gz= \
    ${MASTER_SITE_GITHUB:=catchorg/Catch2/archive/}

SITES.${CRYPTOPP_TAG}.tar.gz= \
    ${MASTER_SITE_GITHUB:=weidai11/cryptopp/archive/}

SITES.${DYNARMIC_TAG}.tar.gz= \
    ${MASTER_SITE_GITHUB:=MerryMage/dynarmic/archive/}

SITES.${ENET_TAG}.tar.gz= \
    ${MASTER_SITE_GITHUB:=lsalzman/enet/archive/}

SITES.${FMT_TAG}.tar.gz= \
    ${MASTER_SITE_GITHUB:=fmtlib/fmt/archive/}

SITES.${INIH_TAG}.tar.gz= \
    ${MASTER_SITE_GITHUB:=benhoyt/inih/archive/}

SITES.${LIBRESSL_TAG}.tar.gz= \
    ${MASTER_SITE_GITHUB:=citra-emu/ext-libressl-portable/archive/}

SITES.${NIHSTRO_TAG}.tar.gz= \
    ${MASTER_SITE_GITHUB:=neobrain/nihstro/archive/}

SITES.${SOUNDTOUCH_TAG}.tar.gz= \
    ${MASTER_SITE_GITHUB:=citra-emu/ext-soundtouch/archive/}

SITES.${XBYAK_TAG}.tar.gz= \
    ${MASTER_SITE_GITHUB:=herumi/xbyak/archive/}

WRKSRC=		${WRKDIR}/citra-${CITRA_TAG}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake

GCC_REQD=	7.3.0

CMAKE_CONFIGURE_ARGS+=	-DENABLE_SDL2=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_LIBRETRO=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_WEB_SERVICE=OFF

# error: unrecognized command line option '-msha'
CMAKE_CONFIGURE_ARGS+=	-DCRYPTOPP_DISABLE_ASM=ON

CMAKE_CONFIGURE_ARGS+=	--target citra_libretro

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

post-extract:
	# Move git submodules into their correct locations.
	# .git files are created to fool cmake.
	${MV} ${WRKDIR}/Catch2-${CATCH_TAG}/* ${WRKSRC}/externals/catch/
	${TOUCH} ${WRKSRC}/externals/catch/.git
	${MV} ${WRKDIR}/cryptopp-${CRYPTOPP_TAG}/* ${WRKSRC}/externals/cryptopp/cryptopp/
	${TOUCH} ${WRKSRC}/externals/cryptopp/cryptopp/.git
	${MV} ${WRKDIR}/dynarmic-${DYNARMIC_TAG}/* ${WRKSRC}/externals/dynarmic/
	${TOUCH} ${WRKSRC}/externals/dynarmic/.git
	${MV} ${WRKDIR}/enet-${ENET_TAG}/* ${WRKSRC}/externals/enet/
	${TOUCH} ${WRKSRC}/externals/enet/.git
	${MV} ${WRKDIR}/ext-boost-${BOOST_TAG}/* ${WRKSRC}/externals/boost/
	${TOUCH} ${WRKSRC}/externals/boost/.git
	${MV} ${WRKDIR}/ext-soundtouch-${SOUNDTOUCH_TAG}/* ${WRKSRC}/externals/soundtouch/
	${TOUCH} ${WRKSRC}/externals/soundtouch/.git
	${MV} ${WRKDIR}/fmt-${FMT_TAG}/* ${WRKSRC}/externals/fmt/
	${TOUCH} ${WRKSRC}/externals/fmt/.git
	${MV} ${WRKDIR}/inih-${INIH_TAG}/* ${WRKSRC}/externals/inih/inih/
	${TOUCH} ${WRKSRC}/externals/inih/inih/.git
	${MV} ${WRKDIR}/nihstro-${NIHSTRO_TAG}/* ${WRKSRC}/externals/nihstro/
	${TOUCH} ${WRKSRC}/externals/libressl/.git
	${MV} ${WRKDIR}/ext-libressl-portable-${LIBRESSL_TAG}/* ${WRKSRC}/externals/libressl/
	${TOUCH} ${WRKSRC}/externals/nihstro/.git
	${MV} ${WRKDIR}/xbyak-${XBYAK_TAG}/* ${WRKSRC}/externals/xbyak/
	${TOUCH} ${WRKSRC}/externals/xbyak/.git

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/citra_libretro/citra_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/citra_libretro.so

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
