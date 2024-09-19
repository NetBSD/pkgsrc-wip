# $NetBSD$

DISTNAME=	downhill-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=d/downhill/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/lmjohns3/downhill
COMMENT=	Stochastic optimization routines for Theano
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-climate>=0.4.6:../../wip/py-climate

WRKSRC=		${WRKDIR}/downhill-0.3.2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
