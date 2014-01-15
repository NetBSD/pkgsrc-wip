# $NetBSD: Makefile,v 1.1 2014/01/15 20:30:56 jihbed Exp $

DISTNAME=	seeds-1.0.13
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://github.com/downloads/briandconnelly/seeds/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	 https://github.com/briandconnelly/seeds
COMMENT=	Stochastic Ecological and Evolutionary Dynamics System
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx

USE_LANGUAGES=	c

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
