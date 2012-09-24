# $NetBSD: Makefile,v 1.9 2012/09/24 17:14:39 asau Exp $
#

DISTNAME=		briquolo-0.5.7
CATEGORIES=		games
MASTER_SITES=		http://briquolo.free.fr/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://briquolo.free.fr/en/
COMMENT=		3D breakout based on OpenGL
LICENSE=		gnu-gpl-v3

INSTALLATION_DIRS+=	share/applications share/briquolo/data/.xvpics
INSTALLATION_DIRS+=	share/pixmaps

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		grep intltool
CONFIGURE_ARGS+=	--with-x --x-includes=${BUILDLINK_PREFIX.libX11}/include
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libX11}/lib
CONFIGURE_ARGS+=	--includedir=${BUILDLINK_PREFIX.MesaLib}/include/GL

post-install:
	cd ${WRKSRC}/data/data; set -e; \
	for FILE in `ls -1 | ${GREP} -v -E '(.xvpics|Makefile)'`; do \
		${INSTALL_DATA} "$$FILE" ${DESTDIR:Q}${PREFIX:Q}/share/briquolo/data/; \
	done; \
	for FILE in .xvpics/*; do \
		${INSTALL_DATA} $$FILE ${DESTDIR:Q}${PREFIX:Q}/share/briquolo/data/$$FILE; \
	done

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
