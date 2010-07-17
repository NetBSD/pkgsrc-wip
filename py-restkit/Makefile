# $NetBSD: Makefile,v 1.3 2010/07/17 01:00:17 jihbed Exp $
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

PYTHON_VERSIONS_INCOMPATIBLE= 24 23 22 21 20

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
