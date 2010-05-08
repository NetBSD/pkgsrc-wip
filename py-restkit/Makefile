# $NetBSD: Makefile,v 1.2 2010/05/08 17:13:38 jihbed Exp $
#

DISTNAME=	restkit-1.3.1.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/r/restkit/
EXTRACT_SUFX=	.gz#md5=4674abf005aee7eb6cd2e848f13fcb52

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/benoitc/restkit/
COMMENT=	Restkit is an HTTP resource kit for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.3.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-oauth>=1.0.1:../../wip/py-oauth
DEPENDS+=	${PYPKGPREFIX}-webob>=0.9.8:../../wip/py-webob

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/restkit-1.3.1
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE= 24 23 22 21 20

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
