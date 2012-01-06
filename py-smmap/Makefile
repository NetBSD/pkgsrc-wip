# $NetBSD: Makefile,v 1.1.1.1 2012/01/06 10:48:28 jihbed Exp $
#

DISTNAME=	smmap-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/s/smmap/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/Byron/smmap
COMMENT=	Git implementation of a sliding window memory map manager
LICENSE=	modified-bsd #Probably

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/smmap-0.8.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
