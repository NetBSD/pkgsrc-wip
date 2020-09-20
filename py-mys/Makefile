# $NetBSD$

DISTNAME=	mys-0.58.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	https://files.pythonhosted.org/packages/48/aa/95462bc2d01a8712721336524da2f14f5528fba67cc7dfbce758de8a4589/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/eerimoq/mys
COMMENT=	Strongly typed Python to C++ transpiler
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.1:../../textproc/py-toml
DEPENDS+=	${PYPKGPREFIX}-ansicolors>=1.1.8:../../wip/py-ansicolors
DEPENDS+=	${PYPKGPREFIX}-humanfriendly>=8.2:../../wip/py-humanfriendly
DEPENDS+=	${PYPKGPREFIX}-yaspin>=1.0.0:../../wip/py-yaspin

USE_LANGUAGES=	c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
