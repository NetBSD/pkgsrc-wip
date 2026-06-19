# $NetBSD$

DISTNAME=	pygame_sdl2-2.1.0-for-renpy-6.99.12.4
PKGNAME=	${PYPKGPREFIX}-game_sdl2-2.1.0.06991204
CATEGORIES=	devel games python
MASTER_SITES=	https://www.renpy.org/dl/6.99.12.4/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/renpy/pygame_sdl2
COMMENT=	Set of Python 2.7 modules designed for writing games for RenPy
LICENSE=	gnu-lgpl-v2.1

PYTHON_27_ACCEPTED=		yes
PYTHON_VERSIONS_ACCEPTED=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../wip/py27-cython

USE_TOOLS+=	pkg-config

EGG_NAME=	pygame_sdl2-2.1.0

REPLACE_PYTHON+=	examples/*.py
REPLACE_PYTHON+=	setup.py

SUBST_CLASSES+=		cython
SUBST_STAGE.cython=	pre-configure
SUBST_MESSAGE.cython=	Use versioned cython_command
SUBST_FILES.cython+=	setuplib.py
SUBST_SED.cython=	-e 's,cython_command = ".*,cython_command = "cython-${PYVERSSUFFIX}",g'

post-extract:
	# Do not use pre-generated cython results.
	# *_api.h is missing and it faild in install stage.
	# These requires correct cython_command.
	${RM} -f ${WRKSRC}/gen/*
	${RM} -f ${WRKSRC}/gen-static/*
	${RM} -f ${WRKSRC}/gen3/*
	# Do not use invalid version number.
	${RM} -f ${WRKSRC}/setup.cfg

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
