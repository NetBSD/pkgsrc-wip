# $NetBSD: Makefile,v 1.2 2010/06/04 12:04:13 jihbed Exp $
#

DISTNAME=	embedc-0.21.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/e/embedc/
EXTRACT_SUFX=	.gz#md5=96a0c4bb74158284a2626ef49bbd0883

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pyembedc.sourceforge.net/
COMMENT=	Python module for embedding C/C++ 
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/embedc-0.21
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
