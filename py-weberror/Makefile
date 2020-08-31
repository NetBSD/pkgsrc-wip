# $NetBSD: Makefile,v 1.8 2015/07/16 11:47:14 thomasklausner Exp $

DISTNAME=	WebError-0.10.2
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/W/w/S/E/e/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WebError/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/WebError/
COMMENT=	Web Error handling and exception catching
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.3.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-paste>=1.7.2:../../www/py-paste
DEPENDS+=	${PYPKGPREFIX}-Tempita>=0.4:../../textproc/py-Tempita
DEPENDS+=	${PYPKGPREFIX}-WebOb>=0.9.8:../../www/py-WebOb

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
