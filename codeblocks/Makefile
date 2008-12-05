# $NetBSD: Makefile,v 1.2 2008/12/05 19:47:13 jsonn Exp $
#

PKGVERSION=	8.02
PKGREVISION=	1
DISTNAME=	codeblocks-${PKGVERSION}-src
PKGNAME=	codeblocks-${PKGVERSION}

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=codeblocks/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.codeblocks.org/
COMMENT=	The open source, cross platform, free C++ IDE

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/codeblocks-8.02
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++
USE_DIRS+= 	xdg-1.4

CONFIGURE_ARGS+=        --with-contrib-plugins=AutoVersioning,BrowseTracker,byogames,cbkoders,codesnippets,codestat,dragscroll,envvars,help,keybinder,libfinder,profiler,regex,exporter,symtab
# wxsmith makes error in build process

PKGCONFIG_OVERRIDE+=	codeblocks.pc.in

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
