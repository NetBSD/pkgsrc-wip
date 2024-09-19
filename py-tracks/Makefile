# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	tracks_0.003
PKGNAME=	${PYPKGPREFIX}-tracks-0.003
CATEGORIES=	biology
MASTER_SITES=	http://molmod.ugent.be/code/static/download/sources/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://molmod.ugent.be/code/wiki/
COMMENT=	Analysis tools for Molecular Dynamics and Monte Carlo simulations
LICENSE=	mit

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test.py

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
