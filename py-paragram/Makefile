# $NetBSD: Makefile,v 1.1.1.1 2011/03/07 11:03:34 jihbed Exp $
#

DISTNAME=	paragram-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://gfxmonk.net/dist/0install/paragram/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://gfxmonk.net/dist/0install/paragram/
COMMENT=	Erlang-style concurrency library for python
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
