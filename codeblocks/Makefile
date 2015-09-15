# $NetBSD: Makefile,v 1.10 2015/09/15 11:26:40 realzhtw Exp $
#

PKGVERSION=	13.12
DISTNAME=	codeblocks_${PKGVERSION}-1
PKGNAME=	codeblocks-${PKGVERSION}
CATEGORIES=	devel
MASTER_SITES=   http://downloads.sourceforge.net/project/codeblocks/Sources/13.12/
EXTRACT_SUFX=	.tar.gz

BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.codeblocks.org/
COMMENT=	Open source, cross platform, free C++ IDE
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
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
