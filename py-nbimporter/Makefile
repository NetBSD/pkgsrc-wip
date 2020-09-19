# $NetBSD$

DISTNAME=	nbimporter-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/48/a0/b1df1a7c12d6add741c21ae509677db4d9a6efb440c25290951cc1216b86/

MAINTAINER=	jihbed.research@gmail.com
Homepage=	https://github.com/grst/nbimporter/
COMMENT=	Import IPython notebooks as modules
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
