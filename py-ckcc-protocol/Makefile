# $NetBSD$

DISTNAME=	ckcc-protocol-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=c/ckcc-protocol/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Coldcard/ckcc-protocol
COMMENT=	Coldcard CLI and python interface library
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click>=6.7:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-aes>=0:../../security/py-aes
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.17:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-hidapi>=0.7.99.post21:../../wip/py-hidapi

USE_LANGUAGES=	# none

REPLACE_PYTHON=		*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
