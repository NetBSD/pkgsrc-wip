# $NetBSD: Makefile,v 1.3 2015/07/15 18:20:12 thomasklausner Exp $

DISTNAME=	wsgiref-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/w/wsgiref/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/wsgiref
COMMENT=	This is a standalone release of the wsgiref library
LICENSE=	zpl-2.0

USE_LANGUAGES=	# none

do-test:
	( cd ${WRKSRC} && ${PYTHONBIN} test_wsgiref.py )

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
