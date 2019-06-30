# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:49 thomasklausner Exp $
#

DISTNAME=	vidalia-0.3.1
PKGNAME=	${DISTNAME:S/-/-devel-/1}
CATEGORIES=	net
MASTER_SITES=	https://www.torproject.org/dist/vidalia/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.torproject.org/vidalia/
COMMENT=	Graphical Tor controller (alpha branch) based on Qt 4.x
LICENSE=	gnu-gpl-v2

DEPENDS+=	tor>=0.2.0.34:../../net/tor

FETCH_BEFORE_ARGS=	--no-check-certificate

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake mkdir

CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR}

pre-configure:
	cd ${WRKSRC} && ${MKDIR} build

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
