# $NetBSD$

DISTNAME=	chempy-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	https://files.pythonhosted.org/packages/0a/29/641d538639c99042da07b33fef7c8cb4412e239f1d5da02c6c072b669538/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/bjodah/chempy
COMMENT=	Python package useful for solving problems in chemistry
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-scipy>=1.0.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=2.2.3:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.6.2:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-quantities>=0.12.4:../../wip/py-quantities
DEPENDS+=	${PYPKGPREFIX}-sym>=0.3.4:../../wip/py-sym
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=6.1.7:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>1.11.3
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
