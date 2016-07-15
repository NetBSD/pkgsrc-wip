# $NetBSD$

DISTNAME=	downhill-0.3.2
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/3c/a2/b4f904fc008a2f6bff3f5d8dd7e18c334b97afebf2acaf1902bc22be4347/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/lmjohns3/downhill
COMMENT=	Stochastic optimization routines for Theano
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-climate>=0.4.6:../../wip/py-climate

WRKSRC=		${WRKDIR}/downhill-0.3.2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
