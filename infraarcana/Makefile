# $NetBSD: Makefile,v 1.1 2015/08/19 19:42:29 yhardy Exp $

DISTNAME=	ia-18.2
PKGNAME=	infraarcana-18.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=martin-tornqvist/}
GITHUB_PROJECT=	ia
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGBASE}
DISTFILES=	${DEFAULT_DISTFILES} rl_utils-${RLUTILSVER}.zip

RLUTILSVER=	757bef657fa43e2d7f41192e07227a00c62236e4

SITES.rl_utils-${RLUTILSVER}.zip=	\
		-${MASTER_SITES:=rl_utils/archive/${RLUTILSVER}.zip}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sites.google.com/site/infraarcana/
COMMENT=	Infra Arcana is a Lovecraftian roguelike set in the early 20th century
LICENSE=	cc-by-nc-sa-v3.0-license

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
USE_GAMESGROUP=	yes

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/InfraArcana
INSTALLATION_DIRS+=	share/InfraArcana/audio
INSTALLATION_DIRS+=	share/InfraArcana/data
INSTALLATION_DIRS+=	share/InfraArcana/images

# See patches/patch-Makefile
BUILD_MAKE_FLAGS+=	X11_LDFLAGS=${X11_LDFLAGS:Q}

post-extract:
	${UNZIP_CMD} -d ${WRKSRC}/rl_utils ${DISTDIR}/${DIST_SUBDIR}/rl_utils-${RLUTILSVER}.zip
	cd ${WRKSRC}/rl_utils && ${MV} rl_utils-${RLUTILSVER}/* .

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/infraarcana.sh > ${WRKSRC}/infraarcana.sh
	${TOUCH} ${WRKSRC}/target/data/highscores

do-install:
	${INSTALL_GAME} ${WRKSRC}/target/ia ${DESTDIR}${PREFIX}/share/InfraArcana
	for f in ${WRKSRC}/target/*.txt; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/InfraArcana/$${f##*/}; \
	done
	for f in ${WRKSRC}/target/audio/*; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/InfraArcana/audio/$${f##*/}; \
	done
	for f in ${WRKSRC}/target/images/*; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/InfraArcana/images/$${f##*/}; \
	done
	${INSTALL_GAME_DATA} ${WRKSRC}/target/data/highscores ${DESTDIR}${PREFIX}/share/InfraArcana/data/
	${INSTALL_GAME_DATA} ${WRKSRC}/target/data/save ${DESTDIR}${PREFIX}/share/InfraArcana/data/
	${INSTALL_SCRIPT} ${WRKSRC}/infraarcana.sh ${DESTDIR}${PREFIX}/bin/infraarcana

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
