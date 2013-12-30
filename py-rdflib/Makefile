# $NetBSD: Makefile,v 1.7 2013/12/30 17:16:36 noud4 Exp $
#

DISTNAME=	rdflib-3.2.2
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/r/rdflib/
FETCH_USING=	curl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://rdflib.net/
COMMENT=	RDF library containing an RDF triple store and RDF/XML parser/serializer
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=1.1.2:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-isodate>=0.4.8:../../wip/py-isodate

WRKSRC=		${WRKDIR}/rdflib-3.2.2

USE_LANGUAGES=	# none

PLIST_SUBST+=		EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
