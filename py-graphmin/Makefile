# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:41 asau Exp $
#

DISTNAME=	graphmin-0.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/graphmin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://river.styx.org/ww/2010/10/graphmin
COMMENT=	RDF Graph Minimisation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-rdflib>=2.4.2:../../textproc/py-rdflib

WRKSRC=		${WRKDIR}/graphmin-0.1.8

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
