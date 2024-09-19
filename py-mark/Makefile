# $NetBSD: Makefile,v 1.5 2013/03/04 21:58:38 thomasklausner Exp $
#

DISTNAME=	mark-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mark/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/mark/
COMMENT=	RDF Bookmarking Utilities
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-argparse>=1.1:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-rdflib>=2.4.2:../../textproc/py-rdflib

WRKSRC=		${WRKDIR}/mark-0.2


USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
