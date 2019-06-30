# $NetBSD: Makefile,v 1.10 2014/06/01 12:49:49 thomasklausner Exp $
#

DISTNAME=	vidalia-0.2.12
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	https://www.torproject.org/vidalia/dist/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	https://www.torproject.org/vidalia/
COMMENT=	Graphical Tor controller based on Qt 4.x
LICENSE=	gnu-gpl-v2

FETCH_BEFORE_ARGS=	--no-check-certificate

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake mkdir

CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR}

# should work with net/tor aswell
DEPENDS+=	tor-[0-9]*:../../net/tor

pre-configure:
	cd ${WRKSRC} && ${MKDIR} build

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
