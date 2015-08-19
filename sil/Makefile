# $NetBSD: Makefile,v 1.1 2015/08/19 19:47:08 yhardy Exp $

DISTNAME=	Sil-121-src
PKGNAME=	sil-1.2.1
CATEGORIES=	games
MASTER_SITES=	http://www.amirrorclear.net/flowers/game/sil/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.amirrorclear.net/flowers/game/sil/
COMMENT=	Roguelike that stays true to the writing of Tolkien
LICENSE=	gnu-gpl-v2 OR angband

WRKSRC=${WRKDIR}/Sil/src

USE_TOOLS+=	gmake
USE_GAMESGROUP=	yes

MAKE_FILE=	Makefile.std

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/Sil
INSTALLATION_DIRS+=	share/Sil
INSTALLATION_DIRS+=	share/Sil/apex
INSTALLATION_DIRS+=	share/Sil/edit
INSTALLATION_DIRS+=	share/Sil/data
INSTALLATION_DIRS+=	share/Sil/pref
INSTALLATION_DIRS+=	share/Sil/xtra
INSTALLATION_DIRS+=	share/Sil/xtra/font
INSTALLATION_DIRS+=	share/Sil/xtra/graf
INSTALLATION_DIRS+=	share/Sil/xtra/sound

CFLAGS+=		-DDEFAULT_PATH='\"${PREFIX}/share/Sil\"'
CFLAGS+=		-DPRIVATE_USER_PATH
CFLAGS+=		-DUSE_PRIVATE_SAVE_PATH
CFLAGS+=		-DUSE_X11 -DUSE_GCU

BUILD_MAKE_FLAGS=	CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_GAME} ${WRKSRC}/sil ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} "${WRKDIR}/Sil/Sil 1.2.1 Manual.pdf" ${DESTDIR}${PREFIX}/share/doc/Sil
	for d in apex edit pref xtra; do \
		cd ${WRKDIR}/Sil/lib && ${FIND} $$d -type f ! -name .DS_Store | while read f; do \
			${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/Sil/$${f%/*} || exit 1; \
		done; \
	done
	for d in data; do \
		cd ${WRKDIR}/Sil/lib && ${FIND} $$d -type f ! -name .DS_Store | while read f; do \
			${INSTALL_GAME_DATA} $$f ${DESTDIR}${PREFIX}/share/Sil/$${f%/*} || exit 1; \
		done; \
	done
	${PRINTF} "" > ${WRKDIR}/Sil/lib/apex/scores.raw
	${INSTALL_GAME_DATA} ${WRKDIR}/Sil/lib/apex/scores.raw ${DESTDIR}${PREFIX}/share/Sil/apex

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
