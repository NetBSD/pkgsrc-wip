# $NetBSD: Makefile,v 1.1.1.1 2011/06/13 19:20:24 jihbed Exp $
#

DISTNAME=	rdf-0.9a6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/r/rdf/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/r/rdf/
COMMENT=	Pure Python package providing the core RDF constructs
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-rdflib>=2.4.2:../../wip/py-rdflib

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/rdf-0.9a6

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_tests.py


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
