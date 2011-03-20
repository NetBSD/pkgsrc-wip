# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 22:38:26 jihbed Exp $
#

DISTNAME=	spectral-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/spectralpython/SPy/0.6/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://spectralpython.sourceforge.net/
COMMENT=	Python module for hyperspectral image processing
LICENSE=	gnu-gpl-v3

#DEPENDS+=	${PYPKGPREFIX}-OpenGL>=3.0.1:../../graphics/py-OpenGL

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
