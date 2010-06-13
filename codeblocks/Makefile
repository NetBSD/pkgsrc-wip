# $NetBSD: Makefile,v 1.6 2010/06/13 22:46:58 thomasklausner Exp $
#

PKGVERSION=	8.02
PKGREVISION=	2
DISTNAME=	codeblocks-${PKGVERSION}-src
PKGNAME=	codeblocks-${PKGVERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=codeblocks/}
EXTRACT_SUFX=	.tar.bz2

BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.codeblocks.org/
COMMENT=	Open source, cross platform, free C++ IDE

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-contrib-plugins=AutoVersioning,BrowseTracker,byogames,cbkoders,codesnippets,codestat,dragscroll,envvars,help,keybinder,libfinder,profiler,regex,exporter,symtab
# wxsmith makes error in build process

PKGCONFIG_OVERRIDE+=	codeblocks.pc.in

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
