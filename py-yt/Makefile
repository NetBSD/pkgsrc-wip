# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:17 othyro Exp $
#

DISTNAME=	yt-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yt/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://yt-project.org/
COMMENT=	Analyzing and visualizing astrophysical simulation output
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
