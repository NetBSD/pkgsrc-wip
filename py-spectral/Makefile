# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:50 thomasklausner Exp $

DISTNAME=	spectral-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spectralpython/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://spectralpython.sourceforge.net/
COMMENT=	Python module for hyperspectral image processing
LICENSE=	gnu-gpl-v3

#DEPENDS+=	${PYPKGPREFIX}-OpenGL>=3.0.1:../../graphics/py-OpenGL
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
