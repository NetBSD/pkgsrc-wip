# $NetBSD: Makefile,v 1.4 2012/04/08 19:09:49 thomasklausner Exp $
#

DISTNAME=	processing-0.52
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	parallel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/processing/
EXTRACT_SUFX=	.zip#md5=62772fa3002d003b2395ed669072d51d

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pyprocessing.berlios.de/
COMMENT=	Library for running multiple Python processes using the threading API
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
