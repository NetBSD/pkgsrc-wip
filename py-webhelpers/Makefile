# $NetBSD: Makefile,v 1.1.1.1 2010/07/31 12:11:07 jihbed Exp $
#

DISTNAME=	WebHelpers-1.0.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/W/w/S/H/h/S/.tar//}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/W/WebHelpers/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://webhelpers.groovie.org/
COMMENT=	Python helper functions for writing templates in web applications
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.6.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-pylons>=0.1:../../wip/py-pylons
DEPENDS+=	${PYPKGPREFIX}-webob>=0.9.8:../../wip/py-webob

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/WebHelpers-1.0
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
