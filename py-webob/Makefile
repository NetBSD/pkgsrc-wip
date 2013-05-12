# $NetBSD: Makefile,v 1.7 2013/05/12 20:36:25 cheusov Exp $
#

DISTNAME=	WebOb-1.2b3
PKGNAME=	${PYPKGPREFIX}-webob-1.2b3
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/W/WebOb/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/packages/source/W/WebOb/
COMMENT=	Python module providing WSGI request and response objects
LICENSE=	mit

DEPENDS+=		${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
