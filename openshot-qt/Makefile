# $NetBSD$

GITHUB_PROJECT=	openshot-qt
GITHUB_TAG=	v2.5.1
DISTNAME=	v2.5.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenShot/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenShot/openshot-qt/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-zmq-[0-9]*:../../net/py-zmq
DEPENDS+=	libopenshot-[0-9]*:../../wip/libopenshot

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
