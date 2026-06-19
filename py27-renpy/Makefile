# $NetBSD$

DISTNAME=	renpy-6.99.12.4-source
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-source//}
CATEGORIES=	games python
MASTER_SITES=	https://www.renpy.org/dl/6.99.12.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.renpy.org/
COMMENT=	Visual Novel Engine written in Python 2.7
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}/module

USE_LANGUAGES+=		c c++
USE_CC_FEATURES+=	c99

USE_TOOLS+=	pax

CFLAGS+=	-Wno-incompatible-pointer-types

PYTHON_27_ACCEPTED=		yes
PYTHON_VERSIONS_ACCEPTED=	27

PYSETUPBUILDTARGET=	build_ext --inplace

REPLACE_PYTHON=		../renpy.py

RENPY_DIR=		share/renpy
INSTALLATION_DIRS=	bin ${RENPY_DIR}
UNAME_M!=		uname -m

RENPY_DEPS_INSTALL+=	${BUILDLINK_PREFIX.SDL2}
RENPY_DEPS_INSTALL+=	${BUILDLINK_PREFIX.freetype2}
RENPY_DEPS_INSTALL+=	${BUILDLINK_PREFIX.zlib}
RENPY_DEPS_INSTALL+=	${BUILDLINK_PREFIX.ffmpeg3}/${BUILDLINK_LIBDIRS.ffmpeg3}

MAKE_ENV+=	RENPY_DEPS_INSTALL=${RENPY_DEPS_INSTALL:ts;:S,;,::,g:Q}
MAKE_ENV+=	RENPY_CYTHON=cython-${PYVERSSUFFIX}

pre-configure:
	cd ${WRKSRC} && find . -name '*.py[co]' -print -delete

post-install:
# For runtime permission denied errors.
.for m in ${RPYC_DIRS}
	cd ${WRKSRC}/.. && \
		PYTHONPATH=build/lib.${LOWER_OPSYS}-${OS_VERSION}-${UNAME_M}-cpython-${PYTHON_VERSION} \
		${PYTHONBIN} ./renpy.py ${m} compile
.endfor
	cd ${WRKSRC}/.. && \
		${FIND} doc gui launcher renpy sdk-fonts the_question \
			tutorial \
			-type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${RENPY_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/../renpy.py ${DESTDIR}${PREFIX}/${RENPY_DIR}
	cd ${DESTDIR}${PREFIX}/bin && \
	${ECHO} '#!${SH}' > renpy-2.7 && \
	${ECHO} '${PYTHONBIN} ${PREFIX}/${RENPY_DIR}/renpy.py "$$@"' >> renpy-2.7 && \
	${CHMOD} 755 renpy-2.7

.include "../../converters/fribidi/buildlink3.mk"
.include "../../wip/py27-game_sdl2/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/py27-cython/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
