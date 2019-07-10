# $NetBSD$

DISTNAME=		wine-4.4
CATEGORIES=		emulators
MASTER_SITES=		https://dl.winehq.org/wine/source/4.x/
EXTRACT_SUFX=		.tar.xz
ABI=			32

MAINTAINER=		zerous@nocebo.space
HOMEPAGE=		http://www.winehq.org/
COMMENT=		Compatibility layer for running Microsoft Windows Applications
LICENSE=		gnu-lgpl-v2.1

ONLY_FOR_PLATFORM+=	*-*-x86_64
GNU_CONFIGURE=		yes
CFLAGS+=		-m32
CONFIGURE_ARGS+=	--disable-tests

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex gmake mktemp msgfmt autoconf perl
REPLACE_PERL+=		tools/winemaker/winemaker tools/winedump/function_grep.pl
NOT_PAX_MPROTECT_SAFE+=	bin/wine

BUILD32=		${WRKSRC}/wine32
BUILD64=		${WRKSRC}/wine64

build-wine64:
	cd ${BUILD64} && ${SETENV} ${MAKE_ENV} ${WKRSRC}/configure ${CONFIGURE_ARGS} --enable-wine64

build-wine32:
	${SETENV} CONFIGURE_ARGS+=--x-libraries=/usr/pkg/emul/netbsd32/lib
	${SETENV} X11_LDFLAGS+=-Wl,-rpath,/usr/pkg/emul/netbsd32/lib
	${SETENV} X11_LDFLAGS+=-L/usr/pkg/emul/netbsd32/lib -lX11
	cd ${BUILD32} && ${SETENV} ${MAKE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS} --with-wine64=${BUILD64}

post-extract:
	${MKDIR} ${BUILD32}
	${MKDIR} ${BUILD32}

do-configure:
	cd ${BUILD32} && ${SETENV} ${MAKE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS}

do-build:
	cd ${BUILD32} && ${SETENV} ${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS}

pre-configure:
	cd ${WRKSRC} && autoconf

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
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
