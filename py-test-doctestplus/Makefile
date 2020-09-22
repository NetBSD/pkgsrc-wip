# $NetBSD$

DISTNAME=	pytest-doctestplus-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/53/0d/23d7f503f1d219bbd66987371eaa4c38149742ed4cdae9dbe6a5576655a0/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://astropy.org/
COMMENT=	Pytest plugin with advanced doctest features
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pip>=20.2.3:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
