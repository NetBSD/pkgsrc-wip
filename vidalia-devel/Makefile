# $NetBSD: Makefile,v 1.2 2012/12/09 21:31:51 othyro Exp $
#

DISTNAME=	vidalia-0.3.1
PKGNAME=	${DISTNAME:S/-/-devel-/1}
CATEGORIES=	net
MASTER_SITES=	https://www.torproject.org/dist/vidalia/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.torproject.org/vidalia/
COMMENT=	Graphical Tor controller (alpha branch) based on Qt 4.x
LICENSE=	gnu-gpl-v2

FETCH_USING=		wget
FETCH_BEFORE_ARGS=	--no-check-certificate

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake mkdir

CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR}

DEPENDS+=	tor>=0.2.0.34:../../net/tor

pre-configure:
		cd ${WRKSRC} && ${MKDIR} build

#do-configure:
#		cd ${WRKSRC}/build && ${CMAKE} ..

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
DEPENDS+=	qt4-tools>=4.3:../../x11/qt4-tools
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
