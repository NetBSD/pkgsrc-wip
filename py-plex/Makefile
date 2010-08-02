# $NetBSD: Makefile,v 1.1.1.1 2010/08/02 21:35:03 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/plex-2.0.0dev
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
