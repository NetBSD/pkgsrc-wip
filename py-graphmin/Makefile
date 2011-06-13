# $NetBSD: Makefile,v 1.1.1.1 2011/06/13 20:27:03 jihbed Exp $
#

DISTNAME=	graphmin-0.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/g/graphmin/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://river.styx.org/ww/2010/10/graphmin
COMMENT=	RDF Graph Minimisation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-rdflib>=2.4.2:../../wip/py-rdflib

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/graphmin-0.1.8

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
