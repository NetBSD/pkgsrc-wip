# $NetBSD$

GITHUB_PROJECT=	qstylizer
GITHUB_TAG=	719c0845d01e724e1f826622b9362435b1e72d73
DISTNAME=	0.2.2
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GITHUB:=blambright/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/blambright/qstylizer/
COMMENT=	Qt Stylesheet Generator for PyQt/PySide
LICENSE=	mit

#BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr>=0:../../devel/py-pbr
DEPENDS+=		${PYPKGPREFIX}-inflection-[0-9]*:../../textproc/py-inflection
DEPENDS+=		${PYPKGPREFIX}-tinycss2-[0-9]*:../../textproc/py-tinycss2

WRKSRC=		${WRKDIR}/qstylizer-${GITHUB_TAG}

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
