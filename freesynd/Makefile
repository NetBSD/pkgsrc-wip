# $NetBSD$

PKGNAME=	freesynd-0.9
DISTNAME=	Freesynd-0.9-Source
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freesynd/freesynd/freesynd-0.9/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://freesynd.sourceforge.io/
COMMENT=	GPLed reimplementation of the engine for the game Syndicate
LICENSE=	gnu-gpl-v3

.include "../../devel/cmake/build.mk"

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++20
GCC_REQD+=		13

INSTALLATION_DIRS+=	share/examples/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/freesynd.ini ${PKG_SYSCONFDIR}/freesynd.ini

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=release -DFS_ETC_DIR="${PKG_SYSCONFDIR}"

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/freesynd.ini ${DESTDIR}${EGDIR}

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/CLI11/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/catch2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/CRCpp/buildlink3.mk"
.include "../../wip/libADLMIDI/buildlink3.mk"
.include "../../wip/utfcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
