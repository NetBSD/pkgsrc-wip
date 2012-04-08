# $NetBSD: Makefile,v 1.4 2012/04/08 19:09:50 thomasklausner Exp $
#

DISTNAME=	restkit-2.0.4.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/r/restkit/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/benoitc/restkit/
COMMENT=	Restkit is an HTTP resource kit for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.3.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-eventlet>=0.9.7:../../wip/py-eventlet
DEPENDS+=	${PYPKGPREFIX}-gevent>=0.13.0:../../wip/py-gevent
DEPENDS+=	${PYPKGPREFIX}-webob>=0.9.8:../../wip/py-webob

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/restkit-2.0.4
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
