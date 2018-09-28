# $NetBSD$

DISTNAME=	pyCraft-1.12.1.20180822
PKGNAME=	${PYPKGPREFIX}-minecraft-${DISTNAME:S/pyCraft-//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ammaraskar/}
GITHUB_PROJECT=	pyCraft
GITHUB_TAG=	0eec179f48c9b4a33da21a4427268c10f0c4713c

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/ammaraskar/pyCraft
COMMENT=	Python minecraft client library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
