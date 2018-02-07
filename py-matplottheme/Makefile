# $NetBSD: Makefile,v 1.1 2014/07/26 20:11:06 jihbed Exp $

DISTNAME=	MatPlotTheme-0.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/MatPlotTheme/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/James-Yu/MatPlotTheme
COMMENT=	MatPlotTheme is a theming library for MatPlotLib
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
