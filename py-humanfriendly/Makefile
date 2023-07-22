# $NetBSD$

DISTNAME=	humanfriendly-10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=h/humanfriendly/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://humanfriendly.readthedocs.io/
COMMENT=	Human friendly output for text interfaces using Python
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-capturer>=2.1:../../wip/py-capturer
TEST_DEPENDS+=	${PYPKGPREFIX}-coloredlogs>=2.0:../../wip/py-coloredlogs

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
