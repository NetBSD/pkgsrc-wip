# $NetBSD$

DISTNAME=	pytest-doctestplus-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/53/0d/23d7f503f1d219bbd66987371eaa4c38149742ed4cdae9dbe6a5576655a0/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://astropy.org/
COMMENT=	Pytest plugin with advanced doctest features
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	pip test

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
