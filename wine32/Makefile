# $NetBSD$

DISTNAME=		wine-4.4
CATEGORIES=		emulators
MASTER_SITES=		https://dl.winehq.org/wine/source/4.x/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		zerous@nocebo.space
HOMEPAGE=		http://www.winehq.org/
COMMENT=		Compatibility layer for running Microsoft Windows Applications
LICENSE=		gnu-lgpl-v2.1

ONLY_FOR_PLATFORM+=	*-*-i386
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tests
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex gmake mktemp msgfmt autoconf perl
REPLACE_PERL+=		tools/winemaker/winemaker tools/winedump/function_grep.pl
NOT_PAX_MPROTECT_SAFE+=	bin/wine

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
