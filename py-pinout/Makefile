# $NetBSD$

GITHUB_PROJECT=	pinout
DISTNAME=	pinout-0.0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=j0ono0/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pinout.readthedocs.io/
COMMENT=	Generate graphical pinout references for electronic hardware
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.0:../../textproc/py-yaml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
