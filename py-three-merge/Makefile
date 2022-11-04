# $NetBSD$

DISTNAME=	three-merge-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/three-merge/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spyder-ide/three-merge
COMMENT=	Simple library for merging two strings with respect to a base one
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-diff-match-patch>=0:../../textproc/py-diff-match-patch

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
