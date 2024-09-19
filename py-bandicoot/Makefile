# $NetBSD$

DISTNAME=	bandicoot-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net graphics
MASTER_SITES=	https://pypi.python.org/packages/0d/22/a1e4b2176f1cb24ed9c6c61d8682a2e8daff159664115de378310fdfde56/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/yvesalexandre/bandicoot
COMMENT=	Toolbox to analyze mobile phone metadata
LICENSE=	mit

DEPENDS+=	nodejs>=6.4.0:../../lang/nodejs
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
