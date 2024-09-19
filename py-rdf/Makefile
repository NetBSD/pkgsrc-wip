# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	rdf-0.9a6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rdf/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://rdflib.net/
COMMENT=	Pure Python package providing the core RDF constructs
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-rdflib>=2.4.2:../../textproc/py-rdflib

WRKSRC=		${WRKDIR}/rdf-0.9a6

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_tests.py


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
