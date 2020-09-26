# $NetBSD$

DISTNAME=	vulture-2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/44/a5/bfc438b2e5d06440c7340d7eeefe98e3af69b3053698cf30ac662f4ebc96/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jendrikseipp/vulture
COMMENT=	Find dead code
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.1:../../textproc/py-toml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
