# $NetBSD$

DISTNAME=	riccipy-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/bc/af/27a90d086b1b374e6efd5439617a5ad6d090dec7700484c17167c89307c4/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/cjayross/riccipy
COMMENT=	Tensor algebra calculator for General Relativity
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=       ${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
.include "../../mk/bsd.pkg.mk"
