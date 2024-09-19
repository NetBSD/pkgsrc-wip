# $NetBSD$

DISTNAME=	greenery-3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/db/c8/9c6989c871b77b093482e641daec9d4a0a45357fa0f2ed3ffa3102a94e7e/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/qntm/greenery
COMMENT=	Manipulation of regular expressions as finite state machines
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
