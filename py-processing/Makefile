# $NetBSD: Makefile,v 1.5 2012/10/07 13:57:26 asau Exp $
#

DISTNAME=	processing-0.52
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	parallel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/processing/}
EXTRACT_SUFX=	.zip#md5=62772fa3002d003b2395ed669072d51d

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pyprocessing.berlios.de/
COMMENT=	Library for running multiple Python processes using the threading API
#LICENSE=	# TODO: (see mk/license.mk)

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
