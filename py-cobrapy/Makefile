# $NetBSD$

DISTNAME=	cobra-0.18.1
PKGNAME=	${PYPKGPREFIX}-cobrapy-0.18.1
CATEGORIES=	biology python
MASTER_SITES=	https://files.pythonhosted.org/packages/ad/4f/ad6e7378a9fb9af80ae856d59adcc41e807ffd0070daf3235594a03ecb5d/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://opencobra.github.io/cobrapy
COMMENT=	Package for constraints-based modeling of biological networks
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-future>=0.18.2:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-depinfo>=1.5.4:../../wip/py-depinfo
DEPENDS+=	${PYPKGPREFIX}-optlang>=1.4.4:../../wip/py-optlang

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.13
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
