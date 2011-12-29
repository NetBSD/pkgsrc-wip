# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:19:38 jihbed Exp $
#

DISTNAME=	yt-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	physics graphics python
MASTER_SITES=	http://pypi.python.org/packages/source/y/yt/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://yt-project.org/
COMMENT=	Analyzing and visualizing astrophysical simulation output
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
