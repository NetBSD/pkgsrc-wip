# $NetBSD: Makefile,v 1.1 2013/12/22 12:48:54 mweckbecker Exp $

DISTNAME=	QtCurve-Gtk2-1.8.16
PKGREVISION=    1
CATEGORIES=	own
MASTER_SITES=	http://craigd.wikispaces.com/file/view/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	m-weckbecker@web.de
HOMEPAGE=	http://craigd.wikispaces.com/file/view/
COMMENT=        A configurable set of widget styles for KDE and Gtk
LICENSE=        gnu-gpl-v2

USE_LANGUAGES=	c c++

CMAKE_OPTS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_OPTS+=	-DSYSCONFDIR=${PKG_SYSCONFDIR}
CMAKE_OPTS+=	-DMANDIR=${PKGMANDIR}
CMAKE_OPTS+=	-DCMAKE_SKIP_BUILD_RPATH:BOOL=ON		\
CMAKE_OPTS+=	-DCMAKE_BUILD_WITH_INSTALL_RPATH:BOOL=ON	\
CMAKE_OPTS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON

BUILD_DEPENDS+= cmake>=0.0:../../devel/cmake
BUILD_DEPENDS+= gtk2+-[0-9]*:../../x11/gtk2

USE_CMAKE=	yes
#WRKSRC=		${WRKDIR}/${DISTNAME}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
