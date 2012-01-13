# $NetBSD: Makefile,v 1.4 2012/01/13 21:55:46 jihbed Exp $
#

DISTNAME=	rdflib-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://rdflib.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://rdflib.net/
COMMENT=	RDF library containing an RDF triple store and RDF/XML parser/serializer

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/rdflib-3.1.0

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_tests.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
