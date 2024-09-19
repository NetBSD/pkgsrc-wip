# $NetBSD$

DISTNAME=	opendune-0.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenDUNE/}
GITHUB_PROJECT=	OpenDUNE

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenDUNE/OpenDUNE
COMMENT=	Open source recreation of Dune II
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
USE_TOOLS+=	gmake pkg-config
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--install-dir=${DESTDIR}
CONFIGURE_ARGS+=	--prefix-dir=${PREFIX}
CONFIGURE_ARGS+=	--binary-dir=bin
CONFIGURE_ARGS+=	--data-dir=share/opendune
CONFIGURE_ARGS+=	--icon-dir=share/pixmaps

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
CONFIGURE_ARGS+=	--with-oss
.else
CONFIGURE_ARGS+=	--without-oss
.endif

.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correct path to OSS device.
SUBST_FILES.oss+=	src/audio/dsp_oss.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.endif

.include "options.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
