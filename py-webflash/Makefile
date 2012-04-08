# $NetBSD: Makefile,v 1.2 2012/04/08 19:09:52 thomasklausner Exp $
#

DISTNAME=	WebFlash-0.1a9.tar
EGG_NAME=	WebFlash-0.1a9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/W/w/S/F/f/S/.tar//}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/W/WebFlash/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://python-rum.org/wiki/WebFlash
COMMENT=	Library to display flash messages in python web applications

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/WebFlash-0.1a9
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE= 25

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
