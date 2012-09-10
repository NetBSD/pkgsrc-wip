# $NetBSD: Makefile,v 1.3 2012/09/10 15:26:22 jihbed Exp $
#

DISTNAME=	WebOb-1.2b3
PKGNAME=	${PYPKGPREFIX}-webob-1.2b3
CATEGORIES=	 www python
MASTER_SITES=	http://pypi.python.org/packages/source/W/WebOb/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/packages/source/W/WebOb/
COMMENT=	Python module providing WSGI request and response objects
LICENSE=	mit

DEPENDS+=		${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 26

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
