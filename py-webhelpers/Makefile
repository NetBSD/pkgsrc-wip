# $NetBSD: Makefile,v 1.7 2015/07/16 11:47:14 thomasklausner Exp $

DISTNAME=	WebHelpers-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WebHelpers/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://webhelpers.groovie.org/
COMMENT=	Python helper functions for writing templates in web applications
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-markupsafe>=0.9.2:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.6.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-pylons>=0.1:../../wip/py-pylons
DEPENDS+=	${PYPKGPREFIX}-WebOb>=0.9.8:../../www/py-WebOb

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-cheetah via py-pylons

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
