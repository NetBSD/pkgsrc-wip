# $NetBSD: Makefile,v 1.4 2010/06/10 17:33:09 othyro Exp $
#

DISTNAME=	vidalia-0.2.9
CATEGORIES=	net security
MASTER_SITES=	https://www.torproject.org/vidalia/dist/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	https://www.torproject.org/vidalia/
COMMENT=	Graphical Tor controller based on Qt 4.x
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

FETCH_CMD=		wget
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
.include "../../mk/bsd.pkg.mk"
