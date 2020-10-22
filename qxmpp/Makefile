# $NetBSD$

GITHUB_PROJECT=	qxmpp
GITHUB_TAG=	v1.3.1
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=qxmpp-project/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/qxmpp-project/qxmpp/
COMMENT=	XMPP client library based on Qt and C++
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/qxmpp-1.3.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	qxmpp.pc.in

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
