# $NetBSD$

DISTNAME=	chempy-0.7.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	https://files.pythonhosted.org/packages/b4/f2/b2d10356dfeb2c48d123af3a1b717bcdfefd5c1cd8fb59a256eb042ddc78/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/bjodah/chempy
COMMENT=	Python package useful for solving problems in chemistry
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-scipy>=1.0.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=2.2.3:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.6.2:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-quantities>=0.12.4:../../wip/py-quantities
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.0.3:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-sym>=0.3.4:../../wip/py-sym
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=6.1.7:../../devel/py-jupyter_client


USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>1.11.3
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
