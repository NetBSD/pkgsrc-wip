# $NetBSD: Makefile,v 1.3 2011/02/25 09:47:49 thomasklausner Exp $
#

DISTNAME=	rdflib-2.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://rdflib.net/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://rdflib.net/
COMMENT=	RDF library containing an RDF triple store and RDF/XML parser/serializer
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 27 26 25 24

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
