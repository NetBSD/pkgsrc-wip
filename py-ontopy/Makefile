# $NetBSD: Makefile,v 1.1.1.1 2011/06/13 19:15:38 jihbed Exp $
#

DISTNAME=	ontopy-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/o/ontopy/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/afternoon/ontopy/
COMMENT=	Simple RDF to Python mapper built on top of rdflib
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ontopy-0.1.1

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
