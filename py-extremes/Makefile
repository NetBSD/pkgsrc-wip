# $NetBSD: Makefile,v 1.1.1.1 2010/07/14 13:13:37 jihbed Exp $
#

DISTNAME=	Extremes-1.1.1
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/E/e/}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/E/Extremes/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/Extremes
COMMENT=	Production-quality Min and Max objects (adapted from PEP 326)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
