# $NetBSD$

DISTNAME=	ggplot-0.11.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/3f/a1/090033eb6be0f62350a2fa209e4813a194431997de6f5486366f5b55b992/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/yhat/ggpy
COMMENT=	Python implementation of the grammar of graphics
LICENSE=	modified-bsd

DEPENDS+=		${PYPKGPREFIX}-brewer2mpl>=1.4.1:../../graphics/py-brewer2mpl
DEPENDS+=		${PYPKGPREFIX}-cycler>=0.10.0:../../graphics/py-cycler
DEPENDS+=		${PYPKGPREFIX}-matplotlib>=2.2.2:../../graphics/py-matplotlib
DEPENDS+=       	${PYPKGPREFIX}-patsy>=0.3.0:../../math/py-patsy
DEPENDS+=		${PYPKGPREFIX}-pandas>=0.23.4:../../math/py-pandas
DEPENDS+=		${PYPKGPREFIX}-scipy>=1.1.0:../../math/py-scipy
DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
