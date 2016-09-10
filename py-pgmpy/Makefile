# $NetBSD$

DISTNAME=	pgmpy-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/35/02/eeaf551776e2b3730609f99efc8394c6ad97deeed2f5333d299ff8e7dfdf/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pgmpy/pgmpy
COMMENT=	Library for Probabilistic Graphical Models
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.1.8:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.18.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18.0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
