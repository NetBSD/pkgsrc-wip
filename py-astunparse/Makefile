# $NetBSD$

VERS=		1.6.3
DISTNAME=	astunparse-1.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/${DISTNAME:S/${VERS}//}/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/simonpercivall/astunparse
COMMENT=	AST unparser for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wheel>=0.23.0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
