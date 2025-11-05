# $NetBSD$

DISTNAME=	bitbox02-7.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitbox02/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BitBoxSwiss/bitbox02-firmware
COMMENT=	Python library for bitbox02 communication
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-base58>=2.0.0:../../converters/py-base58
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.14:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-hidapi>=0.14.0:../../wip/py-hidapi
DEPENDS+=	${PYPKGPREFIX}-semver>=2.8.1:../../devel/py-semver
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.2:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-noiseprotocol>=0.3:../../wip/py-noiseprotocol

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
