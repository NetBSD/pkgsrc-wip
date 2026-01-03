# $NetBSD: Makefile,v 1.57 2025/04/24 14:15:23 wiz Exp $

DISTNAME=	freerdp-3.19.0
PKGNAME=	${DISTNAME:S/freerdp-/freerdp3-/1}
CATEGORIES=	net
MASTER_SITES=	https://pub.freerdp.com/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freerdp.com/
COMMENT=	Free implementation of the Remote Desktop Protocol (major version 3)
LICENSE=	apache-2.0

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

.include "../../devel/cmake/build.mk"

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
#USE_CXX_FEATURES+=	c++20

CMAKE_CONFIGURE_ARGS+=	-DKRB5_ROOT_CONFIG=${KRB5_CONFIG}
CMAKE_CONFIGURE_ARGS+=	-DWITH_SERVER=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_CHANNELS=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_JPEG=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_GSTREAMER_1_0=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_FUSE=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_CLIENT_SDL3=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_BINARY_VERSIONING=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_VERBOSE_WINPR_ASSERT=OFF

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
CMAKE_CONFIGURE_ARGS+=	-DWITH_OSS=ON
LDFLAGS+=	${LIBOSSAUDIO}
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_OSS=OFF
.endif

.include "../../mk/bsd.prefs.mk"

# backtrace(3)
LDFLAGS.NetBSD+=	-lexecinfo

PKGCONFIG_OVERRIDE+=	freerdp.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man7

#post-install:
#	${MV} ${DESTDIR}${PREFIX}/bin/xfreerdp \
#		${DESTDIR}${PREFIX}/bin/xfreerdp2 || ${TRUE}

.include "options.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.if defined(OPSYS_HAS_KQUEUE)
CFLAGS+=	-I${BUILDLINK_PREFIX.libepoll-shim}/include/libepoll-shim
.include "../../devel/libepoll-shim/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
