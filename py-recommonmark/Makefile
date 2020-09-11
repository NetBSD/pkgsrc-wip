# $NetBSD$

DISTNAME=	recommonmark-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=r/recommonmark/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/readthedocs/recommonmark
COMMENT=	Docutils-compatibility bridge to CommonMark
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-commonmark>=0.7.2:../../textproc/py-commonmark

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
