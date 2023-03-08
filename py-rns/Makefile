# $NetBSD$

DISTNAME=	rns-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rns/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://reticulum.network/
COMMENT=	Self-configuring, encrypted and resilient mesh networking stack
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.4.7:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-serial>=3.5:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-netifaces>=0:../../net/py-netifaces

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
