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
WINE32_ARGS+=		--x-libraries=/usr/pkg/emul/netbsd32/lib
WINE32_ARGS+=		--with-wine64=${BUILD64}
WINE64_ARGS+=		--enable-win64
WINE32_ENV+=		CFLAGS+=-m32
WINE32_ENV+=		X11_LDFLAGS+=-Wl,-rpath,/usr/pkg/emul/netbsd32/lib
WINE32_ENV+=		X11_LDFLAGS+=-L/usr/pkg/emul/netbsd32/lib
WINE32_ENV+=		X11_LDFLAGS+=-lX11

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex gmake mktemp msgfmt autoconf perl
REPLACE_PERL+=		tools/winemaker/winemaker tools/winedump/function_grep.pl
NOT_PAX_MPROTECT_SAFE+=	bin/wine
NOT_PAX_MPROTECT_SAFE+= bin/wine64

BUILD32=		${WRKSRC}/wine32
BUILD64=		${WRKSRC}/wine64

post-extract:
	${MKDIR} ${BUILD32}
	${MKDIR} ${BUILD64}

pre-configure:
	cd ${WRKSRC} && autoconf

do-configure:
	cd ${BUILD64} && ${SETENV} ${MAKE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS} ${WINE64_ARGS}
	cd ${BUILD32} && ${SETENV} ${WINE32_ENV} ${MAKE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS} ${WINE32_ARGS}

do-build:
	cd ${BUILD64} && ${SETENV} ${MAKE_ENV} ${MAKE} -j${MAKE_JOBS}
	cd ${BUILD32} && ${SETENV} ${WINE32_ENV} ${MAKE_ENV} ${MAKE} -j${MAKE_JOBS}

do-install:
	cd ${BUILD32} && ${MAKE_ENV} ${MAKE} ${INSTALL_MAKE_FLAGS} install
	cd ${BUILD64} && ${MAKE_ENV} ${MAKE} ${INSTALL_MAKE_FLAGS} install

.include "../../wip/freetype2-32/buildlink3.mk"
.include "../../wip/giflib-32/buildlink3.mk"
.include "../../wip/lcms2-32/buildlink3.mk"
.include "../../wip/png-32/buildlink3.mk"
.include "../../wip/tiff-32/buildlink3.mk"
#.include "../../security/gnutls/buildlink3.mk"
.include "../../wip/mit-krb5-32/buildlink3.mk"
#.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/libxml2-32/buildlink3.mk"
.include "../../wip/libxslt-32/buildlink3.mk"
.include "../../wip/compat80-x11/buildlink3.mk"
.include "../../wip/jpeg-32/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/mit-krb5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
