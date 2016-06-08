# $NetBSD: Makefile,v 1.2 2012/10/07 12:25:35 asau Exp $
#

DISTNAME=	ontopy-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=o/ontopy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/afternoon/ontopy/
COMMENT=	Simple RDF to Python mapper built on top of rdflib
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/ontopy-0.1.1

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
