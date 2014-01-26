# $NetBSD: Makefile,v 1.10 2014/01/26 15:49:58 thomasklausner Exp $

DISTNAME=	PsychoPy-1.61.01
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PsychoPy/pyschopy/}
PKGREVISION=	4
CATEGORIES=	biology python
MASTER_SITES=	http://psychopy.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/psychopy/
COMMENT=	Psychology and neuroscience software in python

#DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL
#PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-Numeric via py-OpenGL

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
