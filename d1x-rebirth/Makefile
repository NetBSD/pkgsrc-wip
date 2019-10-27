# $NetBSD: Makefile,v 1.1 2015/08/19 19:06:08 yhardy Exp $

DISTNAME=	d1x-rebirth_v0.58.1-src
PKGNAME=	d1x-rebirth-0.58.1
CATEGORIES=	games
MASTER_SITES=	http://www.dxx-rebirth.com/download/dxx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dxx-rebirth.com/
COMMENT=	Source port of the Descent 1 engine
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

BUILD_DEPENDS+=		${PYPKGPREFIX}-scons-[0-9]*:../../devel/scons
SCONS=			${PREFIX}/bin/scons
SCONS_ARGS+=		-C ${WRKSRC} prefix=${PREFIX}
SCONS_ARGS+=		sharepath=${PREFIX}/share/d1x-rebirth

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS} ${SCONS_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/d1x-rebirth ${DESTDIR}${PREFIX}/bin

.include "options.mk"

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
