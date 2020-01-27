# $NetBSD$

DISTNAME=		wine-4.4
CATEGORIES=		emulators
MASTER_SITES=		https://dl.winehq.org/wine/source/4.x/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		zerous@nocebo.space
HOMEPAGE=		https://www.winehq.org/
COMMENT=		Compatibility layer for running Microsoft Windows Applications
LICENSE=		gnu-lgpl-v2.1

ONLY_FOR_PLATFORM+=	*-*-i386
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex gmake mktemp msgfmt autoconf perl
REPLACE_PERL+=		tools/winemaker/winemaker tools/winedump/function_grep.pl
NOT_PAX_MPROTECT_SAFE+=	bin/wine

# XXX: Fix warning due to _FORTIFY_SOURCE being redefined
CONFIGURE_ENV+=		ac_cv_c_fortify_enabled=no

# XXX: Disable new_dtags as NetBSD versions prior to 9.0 don't honor DT_RUNPATH
CONFIGURE_ENV+=		ac_cv_cflags__Wl___enable_new_dtags=no

# XXX: Stop Wine from using gethostbyname_r like in linux
CONFIGURE_ENV+=		wine_cv_linux_gethostbyname_r_6=no

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
