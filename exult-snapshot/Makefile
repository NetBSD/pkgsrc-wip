# $NetBSD$

PKGNAME=		${GITHUB_PROJECT}-20170513
DISTNAME=		${GITHUB_TAG}
GITHUB_PROJECT=		exult
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=exult/}
DIST_SUBDIR=		${GITHUB_PROJECT}
GITHUB_TAG=		10b08c3881e68bb52ab76d03ec917927ebda2a08

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://exult.sourceforge.net/
COMMENT=		Open-source Ultima 7 engine

WRKSRC=			${WRKDIR}/exult-${GITHUB_TAG}

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf automake yacc pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh
USE_TOOLS+=	yacc flex

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
