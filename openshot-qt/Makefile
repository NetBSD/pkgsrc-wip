# $NetBSD$

GITHUB_PROJECT=	openshot-qt
GITHUB_TAG=	v2.5.1
DISTNAME=	v2.5.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenShot/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenShot/openshot-qt/
COMMENT=	Video editor
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-zmq-[0-9]*:../../net/py-zmq
DEPENDS+=	libopenshot-[0-9]*:../../wip/libopenshot

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
