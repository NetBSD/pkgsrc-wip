# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:26 asau Exp $
#

DISTNAME=	plex-2.0.0dev.tar
EGG_NAME=	plex-2.0.0dev
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dev.tar//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/plex/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/python-plex/
COMMENT=	Plex is a library building lexical analysers
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/plex-2.0.0dev
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
