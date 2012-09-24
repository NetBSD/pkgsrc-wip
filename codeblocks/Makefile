# $NetBSD: Makefile,v 1.9 2012/09/24 18:26:54 asau Exp $
#

PKGVERSION=	10.05
DISTNAME=	codeblocks-${PKGVERSION}-src
PKGNAME=	codeblocks-${PKGVERSION}
CATEGORIES=	devel
MASTER_SITES=	http://download.berlios.de/codeblocks/
EXTRACT_SUFX=	.tar.bz2

BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.codeblocks.org/
COMMENT=	Open source, cross platform, free C++ IDE
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}-release
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-contrib-plugins=AutoVersioning,BrowseTracker,byogames,cbkoders,codesnippets,codestat,dragscroll,envvars,help,keybinder,libfinder,profiler,regex,exporter,symtab
# wxsmith makes error in build process

PKGCONFIG_OVERRIDE+=	codeblocks.pc.in

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
