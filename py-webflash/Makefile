# $NetBSD: Makefile,v 1.4 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	WebFlash-0.1a9.tar
EGG_NAME=	WebFlash-0.1a9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/W/w/S/F/f/S/.tar//}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WebFlash/}
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://python-rum.org/wiki/WebFlash
COMMENT=	Library to display flash messages in python web applications

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson

WRKSRC=		${WRKDIR}/WebFlash-0.1a9
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
