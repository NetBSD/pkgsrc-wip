# $NetBSD: Makefile,v 1.1 2015/08/19 20:11:36 yhardy Exp $
#

DISTNAME=	naev-${NAEV_VER}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=naev/}
GITHUB_TAG=	naev-${NAEV_VER}
NAEV_VER=	0.7.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://naev.org/
COMMENT=	2D space trading and combat game
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-lua=shared

USE_TOOLS+=		autoconf automake pkg-config

LUA_VERSIONS_ACCEPTED=	51

NAEV_DATADIR=		${PREFIX}/share/${DISTNAME}

SUBST_CLASSES+=		ndata
SUBST_STAGE.ndata=	post-patch
SUBST_FILES.ndata=	src/ndata.c
SUBST_SED.ndata=	-e "s,@DATADIR@,${NAEV_DATADIR},"

BUILD_TARGET=		all ndata.zip
INSTALL_TARGET=		install install-ndata

BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
