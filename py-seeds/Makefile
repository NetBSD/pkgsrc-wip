# $NetBSD: Makefile,v 1.2 2014/01/26 15:49:59 thomasklausner Exp $

DISTNAME=	seeds-1.0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://github.com/downloads/briandconnelly/seeds/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/briandconnelly/seeds
COMMENT=	Stochastic Ecological and Evolutionary Dynamics System
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx

USE_LANGUAGES=	c

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-networkx

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
