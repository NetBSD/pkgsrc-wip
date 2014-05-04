# $NetBSD: Makefile,v 1.1 2014/05/04 22:27:46 jihbed Exp $

DISTNAME=	cma-1.0.02beta
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/c/cma/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.lri.fr/~hansen/cmaes_inmatlab.html#python
COMMENT=	Covariance Matrix Adaptation Evolution Strategy for non-linear
LICENSE=	mit

WRKSRC=		${WRKDIR}/cma-1.0.02beta

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
