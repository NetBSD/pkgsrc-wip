# $NetBSD$

GITHUB_PROJECT=	branca
GITHUB_TAG=	ac45f1e1fa95d10a2409409cf3c697f700cad314
DISTNAME=	master
VERSION=	0.4.1
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=python-visualization/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://github.com/python-visualization/branca/
COMMENT=	Generate complex HTML+JS pages with Python
LICENSE=	mit

BUILD_DEPENDS+=	py37-setuptools>=50.0:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-python37>=0:../../lang/python37
DEPENDS+=	${PYPKGPREFIX}-jinja2>=0:../../textproc/py-jinja2


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
