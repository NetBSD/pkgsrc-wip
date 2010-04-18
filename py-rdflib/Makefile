# $NetBSD: Makefile,v 1.2 2010/04/18 14:23:38 jihbed Exp $
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

PYTHON_VERSIONS_ACCEPTED= 26 25 24

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
