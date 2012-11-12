# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:51 othyro Exp $
#

DISTNAME=	spectral-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spectralpython/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://spectralpython.sourceforge.net/
COMMENT=	Python module for hyperspectral image processing
LICENSE=	gnu-gpl-v3

#DEPENDS+=	${PYPKGPREFIX}-OpenGL>=3.0.1:../../graphics/py-OpenGL

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
