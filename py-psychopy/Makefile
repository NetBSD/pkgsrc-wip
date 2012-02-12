# $NetBSD: Makefile,v 1.6 2012/02/12 19:58:29 noud4 Exp $
#

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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 26 25

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
