# $NetBSD: Makefile,v 1.5 2014/01/25 10:38:23 thomasklausner Exp $

DISTNAME=	WebError-0.10.2
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/W/w/S/E/e/}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/W/WebError/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/WebError/
COMMENT=	Web Error handling and exception catching
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.3.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-Paste>=1.7.2:../../www/py-paste
DEPENDS+=	${PYPKGPREFIX}-Tempita>=0.4:../../textproc/py-Tempita
DEPENDS+=	${PYPKGPREFIX}-webob>=0.9.8:../../wip/py-webob

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-paste

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
