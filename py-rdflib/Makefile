# $NetBSD: Makefile,v 1.9 2014/06/01 12:49:45 thomasklausner Exp $

DISTNAME=	rdflib-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	https://pypi.python.org/packages/source/r/rdflib/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/RDFLib/rdflib
COMMENT=	Python library for working with RDF
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.0.1:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.95:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-isodate>=0.4.9:../../wip/py-isodate
#DEPENDS+=	${PYPKGPREFIX}-sparqlwrapper>=1.5.2:../../wip/py-sparqlwrapper

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
