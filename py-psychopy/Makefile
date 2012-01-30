# $NetBSD: Makefile,v 1.3 2012/01/30 03:06:25 noud4 Exp $
#

DISTNAME=	PsychoPy-1.61.01
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PsychoPy/pyschopy/}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	http://psychopy.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/psychopy/
COMMENT=	Psychology and neuroscience software in python

DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.2:../../devel/py-ctypes
#DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 26 25

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
