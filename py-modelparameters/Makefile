# $NetBSD$

DISTNAME=	modelparameters-2019.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category python
MASTER_SITES=	https://files.pythonhosted.org/packages/ed/25/82f6111ff641f668cb3fcc496b2096b32462bbb18334f3051c5bcfc28a6b/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/finsberg/modelparameters
COMMENT=	Module providing parameter structure for physical modeling
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
#DEPENDS+=	${PYPKGPREFIX}-pint>=0.14:../../wip/py-pint

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
