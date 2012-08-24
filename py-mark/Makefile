# $NetBSD: Makefile,v 1.2 2012/08/24 10:26:17 jihbed Exp $
#

DISTNAME=	mark-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www devel python
MASTER_SITES=	http://pypi.python.org/packages/source/m/mark/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/mark/
COMMENT=RDF Bookmarking Utilities
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-argparse>=1.1:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-rdflib>=2.4.2:../../wip/py-rdflib

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/mark-0.2


USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
