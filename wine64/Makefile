# $NetBSD$

DISTNAME=		wine-4.4
CATEGORIES=		emulators
MASTER_SITES=		https://dl.winehq.org/wine/source/4.x/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		zerous@nocebo.space
HOMEPAGE=		http://www.winehq.org/
COMMENT=		Compatibility layer for running Microsoft Windows Applications
LICENSE=		gnu-lgpl-v2.1

ONLY_FOR_PLATFORM+=	*-*-x86_64
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tests
#WINE32_ARGS+=		--x-libraries=${PREFIX}/emul/netbsd32/lib
WINE32_ARGS+=		--with-wine64=${BUILD64}
WINE32_ARGS+=		--libdir=${PREFIX}/emul/netbsd32/lib/wine
WINE64_ARGS+=		--enable-win64
WINE64_ARGS+=		--libdir=${PREFIX}/lib
WINE32_ENV+=		CFLAGS+=-m32
# WINE32_ENV+=		X11_LDFLAGS+=${COMPILER_RPATH_FLAG}${PREFIX}/emul/netbsd32/lib
# WINE32_ENV+=		X11_LDFLAGS+=-L${PREFIX}/emul/netbsd32/lib
# WINE32_ENV+=		X11_LDFLAGS+=-lX11
# WINE32_ENV+=		PKG_CONFIG_PATH=${PREFIX}/emul/netbsd32/lib:${PREFIX}/lib

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex gmake mktemp msgfmt autoconf perl
REPLACE_PERL+=		tools/winemaker/winemaker tools/winedump/function_grep.pl
NOT_PAX_MPROTECT_SAFE+=	bin/wine
NOT_PAX_MPROTECT_SAFE+=	bin/wine64
# XXX: pkgsrc complains that libwine.so.1 is missing prior installation
CHECK_SHLIBS_SKIP=	bin/wine*

BUILD32=		${WRKSRC}/wine32
BUILD64=		${WRKSRC}/wine64
#_PKG_CONFIG_LIBDIR=	${BUILDLINK_DIR}/emul/netbsd32/lib/pkgconfig:${BUILDLINK_DIR}/lib/pkgconfig:${BUILDLINK_DIR}/share/pkgconfig

post-extract:
	${MKDIR} ${BUILD32}
	${MKDIR} ${BUILD64}

# XXX: Unlink libs and *.pc files of fontconfig and freetype that comes with compat80-x11
pre-configure:
	cd ${BUILDLINK_X11_DIR:Q}/emul/netbsd32/lib && find . -name "*fontconfig*" -maxdepth 1 -type l -delete && find ./pkgconfig/ -name "*fontconfig.pc*" -type l -delete
	cd ${BUILDLINK_X11_DIR:Q}/emul/netbsd32/lib && find . -name "*freetype*" -maxdepth 1 -type l -delete && find ./pkgconfig/ -name "*freetype2.pc*" -type l -delete
	cd ${WRKSRC} && autoconf

do-configure:
	cd ${BUILD64} && ${SETENV} ${MAKE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS} ${WINE64_ARGS}
	cd ${BUILD32} && ${SETENV} ${WINE32_ENV} ${MAKE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS} ${WINE32_ARGS}

do-build:
	cd ${BUILD64} && ${SETENV} ${MAKE_ENV} ${MAKE} -j${MAKE_JOBS}
	cd ${BUILD32} && ${SETENV} ${WINE32_ENV} ${MAKE_ENV} ${MAKE} -j${MAKE_JOBS}

do-install:
	cd ${BUILD32} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${MAKE} ${INSTALL_MAKE_FLAGS} install
	cd ${BUILD64} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${MAKE} ${INSTALL_MAKE_FLAGS} install

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/mit-krb5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../wip/compat32_fontconfig/buildlink3.mk"
.include "../../wip/compat32_freetype2/buildlink3.mk"
.include "../../wip/compat32_giflib/buildlink3.mk"
.include "../../wip/compat32_jpeg/buildlink3.mk"
.include "../../wip/compat32_lcms2/buildlink3.mk"
.include "../../wip/compat32_libxml2/buildlink3.mk"
.include "../../wip/compat32_libxslt/buildlink3.mk"
.include "../../wip/compat32_mit-krb5/buildlink3.mk"
.include "../../wip/compat32_png/buildlink3.mk"
.include "../../wip/compat32_tiff/buildlink3.mk"
.include "../../wip/compat80-x11/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
