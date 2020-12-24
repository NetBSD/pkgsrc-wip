# $NetBSD: Makefile,v 1.1 2015/08/19 19:06:08 yhardy Exp $

DISTNAME=	dxx-rebirth_20201216-src
PKGNAME=	d2x-rebirth-20201216
CATEGORIES=	games
MASTER_SITES=	https://www.dxx-rebirth.com/download/dxx/rebirth/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dxx-rebirth.com/
COMMENT=	Source port of the Descent 2 engine
#LICENSE=	parallax AND (gnu-gpl3-v3 WITH exception)

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

BUILD_DEPENDS+=		${PYPKGPREFIX}-scons-[0-9]*:../../devel/scons
SCONS=			${PREFIX}/bin/scons
SCONS_ARGS+=		-C ${WRKSRC}
SCONS_ARGS+=		DESTDIR=${DESTDIR}
SCONS_ARGS+=		d2x=
SCONS_ARGS+=		prefix=${PREFIX}
SCONS_ARGS+=		sdlmixer=1
SCONS_ARGS+=		sharepath=${PREFIX}/share/d2x-rebirth

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 38 39
PYTHON_FOR_BUILD_ONLY=	yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS} ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS} ${SCONS_ARGS} install

.include "options.mk"

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
