# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:43 thomasklausner Exp $

DISTNAME=	minepy-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=m/minepy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	minepy.sourceforge.net
COMMENT=	Maximal Information-based Nonparametric Exploration
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

post-extract:
	${MV} ${WRKSRC}/minepy/scripts/mine ${WRKSRC}/minepy/scripts/mine${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
