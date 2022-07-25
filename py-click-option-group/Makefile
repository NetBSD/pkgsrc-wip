# $NetBSD$

DISTNAME=	click-option-group-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click-option-group/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/click-contrib/click-option-group
COMMENT=	Option groups missing in Click
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click

USE_LANGUAGES=	# none

# Only for Python >= 3.6
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
