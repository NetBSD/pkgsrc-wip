# $NetBSD$

GITHUB_PROJECT=	NBlood
GITHUB_TAG=	197c38fe2a6a05cfd35c1c9bb039dcbee6e9c095
DISTNAME=	NBlood-current
PKGNAME=	NBlood-current
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=nukeykt/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	astr0b4by@gmail.com
HOMEPAGE=	https://github.com/nukeykt/NBlood/
COMMENT=	Reverse-engineered Blood
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/NBlood-197c38fe2a6a05cfd35c1c9bb039dcbee6e9c095
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake pkg-config
NO_CONFIGURE=	yes
MAKE_ENV+=	prefix=${PREFIX}
MAKE_FILE=	GNUmakefile


BUILD_DEPENDS=	nasm-[0-9]*:../../devel/nasm

BUILD_MAKE_FLAGS+=	LTO=0 RELEASE=1 USE_LIBVPX=0

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nblood ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rednukem ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pcexhumed ${DESTDIR}${PREFIX}/bin

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
