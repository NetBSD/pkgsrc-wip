# $NetBSD$

DISTNAME=	Expression-0.45.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=E/Expression/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/cognitedata/expression
COMMENT=	Practical functional programming for Python 3.8+
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	39 38

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner>=5.2:../../devel/py-test-runner
	
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
