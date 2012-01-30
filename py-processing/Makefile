# $NetBSD: Makefile,v 1.2 2012/01/30 03:04:41 noud4 Exp $
#

DISTNAME=	processing-0.52
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	parallel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/processing/
EXTRACT_SUFX=	.zip#md5=62772fa3002d003b2395ed669072d51d

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pyprocessing.berlios.de/
COMMENT=	Library for running multiple Python processes using the threading API
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.2:../../devel/py-ctypes

#python section
PYTHON_VERSIONS_INCOMPATIBLE=  \
			23 22 21 20 15
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
