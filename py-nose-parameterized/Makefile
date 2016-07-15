# $NetBSD$

DISTNAME=	nose-parameterized-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/0d/22/44ff04785ff8a1e4f618a39b20e6d96e1dbb33088fc13d690a035b12b3f6/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/wolever/nose-parameterized
COMMENT=	Parameterized testing with any Python test framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose

WRKSRC=		${WRKDIR}/nose-parameterized-0.5.0
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
