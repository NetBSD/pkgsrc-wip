# $NetBSD$

DISTNAME=		wine-4.13
CATEGORIES=		emulators
MASTER_SITES=		https://dl.winehq.org/wine/source/4.x/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		zerous@nocebo.space
HOMEPAGE=		https://www.winehq.org/
COMMENT=		Compatibility layer for running Microsoft Windows Applications
LICENSE=		gnu-lgpl-v2.1

ONLY_FOR_PLATFORM+=	*-*-x86_64
GNU_CONFIGURE=		yes
WINE32_ARGS+=		--with-wine64=${BUILD64}
WINE32_ARGS+=		--with-freetype=${PREFIX}/emul/netbsd32/lib/freetype2
WINE32_ARGS+=		--with-fontconfig=${PREFIX}/emul/netbsd32/lib/fontconfig
WINE32_ARGS+=		--libdir=${PREFIX}/emul/netbsd32/lib/wine
WINE64_ARGS+=		--enable-win64
WINE64_ARGS+=		--libdir=${PREFIX}/lib

WINE32_ENV=		CFLAGS+=-m32

# XXX: Fix warning due to _FORTIFY_SOURCE being redefined
WINE_ENV=		ac_cv_c_fortify_enabled=no

# XXX: Disable new_dtags as NetBSD versions prior to 9.0 don't honor DT_RUNPATH
WINE_ENV+=	ac_cv_cflags__Wl___enable_new_dtags=no

# XXX: Stop Wine from gethostbyname_r like in linux
WINE_ENV+=		wine_cv_linux_gethostbyname_r_6=no

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex gmake mktemp msgfmt autoconf perl
REPLACE_PERL+=		tools/winemaker/winemaker tools/winedump/function_grep.pl
NOT_PAX_MPROTECT_SAFE+=	bin/wine
NOT_PAX_MPROTECT_SAFE+=	bin/wine64

# XXX: pkgsrc complains that i386.so.2 is missing
CHECK_SHLIBS_SKIP+=	emul/netbsd32/lib/wine*
CHECK_SHLIBS_SKIP+=	libexec/wine

BUILD32=		${WRKSRC}/wine32
BUILD64=		${WRKSRC}/wine64

post-extract:
	${MKDIR} ${BUILD32}
	${MKDIR} ${BUILD64}

pre-configure:
	cd ${WRKSRC} && autoreconf

do-configure:
	cd ${BUILD64} && ${SETENV} ${WINE_ENV} ${MAKE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS} ${WINE64_ARGS}
	cd ${BUILD32} && ${SETENV} ${WINE_ENV} ${WINE32_ENV} ${MAKE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS} ${WINE32_ARGS}

do-build:
	cd ${BUILD64} && ${SETENV} ${MAKE_ENV} ${MAKE} -j${MAKE_JOBS:U1}
	cd ${BUILD32} && ${SETENV} ${WINE32_ENV} ${MAKE_ENV} ${MAKE} -j${MAKE_JOBS:U1}

do-install:
	cd ${BUILD32} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${MAKE} ${INSTALL_MAKE_FLAGS} install
	cd ${BUILD64} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${MAKE} ${INSTALL_MAKE_FLAGS} install

post-install:
	${SED} -e 's,@PREFIX@,${PREFIX},g' <${FILESDIR}/wine.in \
	>${WRKDIR}/wine
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/libexec
	${MV} ${DESTDIR}${PREFIX}/bin/wine ${DESTDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/wine ${DESTDIR}${PREFIX}/bin/wine

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
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
