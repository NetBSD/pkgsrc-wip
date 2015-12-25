# $NetBSD: Makefile,v 1.1 2015/08/19 19:42:29 yhardy Exp $

DISTNAME=	ia-17.0
PKGNAME=	infraarcana-17.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=InfraArcana/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sites.google.com/site/infraarcana/
COMMENT=	Infra Arcana is a Lovecraftian roguelike set in the early 20th century
LICENSE=	cc-by-nc-sa-v3.0-license

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
USE_GAMESGROUP=	yes

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/InfraArcanum
INSTALLATION_DIRS+=	share/InfraArcanum/audio
INSTALLATION_DIRS+=	share/InfraArcanum/data
INSTALLATION_DIRS+=	share/InfraArcanum/images

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/infraarcanum.sh > ${WRKSRC}/infraarcanum.sh
	${TOUCH} ${WRKSRC}/target/data/highscores

do-install:
	${INSTALL_GAME} ${WRKSRC}/target/ia ${DESTDIR}${PREFIX}/share/InfraArcanum
	for f in ${WRKSRC}/target/*.txt; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/InfraArcanum/$${f##*/}; \
	done
	for f in ${WRKSRC}/target/audio/*; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/InfraArcanum/audio/$${f##*/}; \
	done
	for f in ${WRKSRC}/target/images/*; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/InfraArcanum/images/$${f##*/}; \
	done
	${INSTALL_GAME_DATA} ${WRKSRC}/target/ascii_graveyard ${DESTDIR}${PREFIX}/share/InfraArcanum/
	${INSTALL_GAME_DATA} ${WRKSRC}/target/data/highscores ${DESTDIR}${PREFIX}/share/InfraArcanum/data/
	${INSTALL_SCRIPT} ${WRKSRC}/infraarcanum.sh ${DESTDIR}${PREFIX}/bin/infraarcanum

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
