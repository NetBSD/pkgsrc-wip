# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	Theano-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/}
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/T/Theano/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://deeplearning.net/software/theano/
COMMENT= Optimizing compiler for evaluating mathematical expressions on CPU/GPU
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

WRKSRC=		${WRKDIR}/Theano-0.3.0

USE_TOOLS+=	pax
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/doc/py-theano

do-test:
	${RUN} cd ${WRKSRC}/theano/tests ; ${SETENV} ${TEST_ENV} ${PYTHONBIN}  main.py

post-install:
	cd ${WRKSRC}/doc && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/py-theano

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
