# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:33 asau Exp $
#

DISTNAME=	yt-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	physics graphics python
MASTER_SITES=	http://pypi.python.org/packages/source/y/yt/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://yt-project.org/
COMMENT=	Analyzing and visualizing astrophysical simulation output
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
