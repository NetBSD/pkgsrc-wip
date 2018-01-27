# $NetBSD: Makefile,v 1.1 2015/07/11 00:46:11 jihbed Exp $

DISTNAME=	mendeleev-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mendeleev/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/lukaszmentel/mendeleev
COMMENT=	Database of atomic properties for elements in the periodic table
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.9.9:../../databases/py-sqlalchemy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
