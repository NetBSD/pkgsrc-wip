# $NetBSD$

GITHUB_PROJECT=	BrogueCE
GITHUB_TAG=	v1.9.3
DISTNAME=	${GITHUB_TAG}
PKGNAME=	brogue-ce-${GITHUB_TAG:S,^v,,}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=tmewett/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tmewett/BrogueCE/
COMMENT=	Community edition of the brogue roguelike game
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/BrogueCE-${PKGVERSION_NOREV}
USE_TOOLS+=	gmake

BUILD_TARGET=	bin/brogue
FILES_SUBST+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DATADIR=${PREFIX}/share/brogue-ce
MAKE_FLAGS+=	TERMINAL=YES

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/brogue-ce
INSTALLATION_DIRS+=	share/doc/brogue-ce

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-install
SUBST_FILES.paths=	brogue-ce.sh
SUBST_VARS.paths=	PREFIX

pre-configure:
	${CP} ${FILESDIR}/brogue-ce.sh ${WRKSRC}/brogue-ce.sh

do-install: ${BROGUE_CE_ASSETS}
	${INSTALL_SCRIPT} ${WRKSRC}/brogue-ce.sh ${DESTDIR}${PREFIX}/bin/brogue-ce
	${INSTALL_ASSETS} ${WRKSRC}/bin/assets/* ${DESTDIR}${PREFIX}/share/brogue-ce/assets/
	${INSTALL_GAME} ${WRKSRC}/bin/brogue ${DESTDIR}${PREFIX}/share/brogue-ce/
	${INSTALL_DATA} ${WRKSRC}/bin/keymap.txt ${DESTDIR}${PREFIX}/share/brogue-ce/
	${INSTALL_DATA} ${WRKSRC}/*.md ${DESTDIR}${PREFIX}/share/doc/brogue-ce/
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/brogue-ce/

.include "options.mk"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
