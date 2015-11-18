# $NetBSD: Makefile,v 1.1 2015/08/19 20:11:36 yhardy Exp $
#

DISTNAME=	naev-${NAEV_VER}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=project/naev/naev-${NAEV_VER}/}
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ndata-${NAEV_VER}.zip
NAEV_VER=	0.6.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://naev.org/
COMMENT=	2D space trading and combat game
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-lua=shared

USE_TOOLS+=		pkg-config

LUA_VERSIONS_ACCEPTED=	51

NAEV_DATADIR=		${PREFIX}/share/${DISTNAME}

# until naev catches up with latest lua
CFLAGS+=		-DluaL_reg=luaL_Reg
CFLAGS+=		-D_GNU_SOURCE=1

SUBST_CLASSES+=		ndata
SUBST_STAGE.ndata=	post-patch
SUBST_FILES.ndata=	src/ndata.c
SUBST_SED.ndata=	-e "s,@DATADIR@,${NAEV_DATADIR},"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${NAEV_DATADIR}
	${INSTALL_DATA} ${DISTDIR}/ndata-${NAEV_VER}.zip ${DESTDIR}${NAEV_DATADIR}

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
