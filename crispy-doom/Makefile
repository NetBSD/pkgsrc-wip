# $NetBSD$

DISTNAME=	crispy-doom-5.9.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=fabiangreffrath/}
GITHUB_TAG=	${DISTNAME}
EXTRACT_USING=	bsdtar

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://github.com/fabiangreffrath/crispy-doom/
COMMENT=	Limit-removing enhanced-resolution Doom source port
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c99
USE_TOOLS+=	autoconf automake pkg-config

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/crispy-doom-${DISTNAME}

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=	share/doom

# Add DOOMWADDIR to search path
SUBST_CLASSES+=		waddir
SUBST_STAGE.waddir=	pre-configure
SUBST_MESSAGE.waddir=	Preparing d_iwad.c file ...
SUBST_FILES.waddir=	src/d_iwad.c
SUBST_SED.waddir=	-e 's,PKGSRC_PREFIX,"${PREFIX}",'
SUBST_SED.waddir+=	-e 's,PKGSRC_DOOMWADDIR,"/${DOOMWADDIR}",'

pre-configure:
	cd ${WRKSRC} && ./autogen.sh
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/INSTALL.pkgsrc \
		${DESTDIR}${PREFIX}/share/doc/crispy-doom/INSTALL.pkgsrc

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
