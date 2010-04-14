# $NetBSD: Makefile,v 1.1.1.1 2010/04/14 20:28:25 jihbed Exp $
#

DISTNAME=	wsgiref-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/w/wsgiref/
EXTRACT_SUFX=	.zip#md5=29b146e6ebd0f9fb119fe321f7bcf6cb

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/wsgiref
COMMENT=	This is a standalone release of the wsgiref library
LICENSE=		zpl

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

do-test:
	( cd ${WRKSRC} && ${PYTHONBIN} test_wsgiref.py )

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
