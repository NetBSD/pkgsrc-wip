# $NetBSD$

DISTNAME=	locket-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=l/locket/}


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/mwilliamson/locket/
COMMENT=	File based locks for Python for Linux and Windows
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.2.1:../../devel/py-nose


USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
