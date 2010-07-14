# $NetBSD: Makefile,v 1.1.1.1 2010/07/14 13:21:25 jihbed Exp $
#

DISTNAME=	WebError-0.10.2.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/W/w/S/E/e/S/.tar//}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/W/WebError/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/WebError/
COMMENT=	Web Error handling and exception catching
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.3.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-Paste>=1.7.2:../../www/py-paste
DEPENDS+=	${PYPKGPREFIX}-tempita>=0.4:../../wip/py-tempita
DEPENDS+=	${PYPKGPREFIX}-webob>=0.9.8:../../wip/py-webob

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/WebError-0.10.2
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
