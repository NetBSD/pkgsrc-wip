# $NetBSD$

DISTNAME=	ipydex-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://files.pythonhosted.org/packages/2a/40/822f40cb15af077e51dea4b7464b863b58163e502bb19030ad1ee65a5a12/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/cknoll/ipydex
COMMENT=	IPython based debugging and exploring
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-ipython>=7.2.0:../../devel/py-ipython

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
