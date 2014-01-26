# $NetBSD: Makefile,v 1.3 2014/01/26 15:49:59 thomasklausner Exp $

DISTNAME=	WebHelpers-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/W/w/S/H/h/}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/W/WebHelpers/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://webhelpers.groovie.org/
COMMENT=	Python helper functions for writing templates in web applications
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.6.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-pylons>=0.1:../../wip/py-pylons
DEPENDS+=	${PYPKGPREFIX}-webob>=0.9.8:../../wip/py-webob

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-cheetah and py-paste via py-pylons

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
