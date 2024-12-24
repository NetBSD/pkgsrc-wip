# $NetBSD$

DISTNAME=	openshot-qt-3.3.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenShot/}
GITHUB_PROJECT=	openshot-qt
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenShot/openshot-qt/
COMMENT=	Video editor
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-zmq-[0-9]*:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-requests>=2.26.0:../../devel/py-requests
DEPENDS+=	libopenshot-[0-9]*:../../wip/libopenshot
DEPENDS+=	${PYPKGPREFIX}-qt5-webengine-[0-9]*:../../x11/py-qt5-webengine

REPLACE_PYTHON+=	src/*/*.py

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
