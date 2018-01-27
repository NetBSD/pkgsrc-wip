# $NetBSD: Makefile,v 1.1 2015/08/19 19:47:08 yhardy Exp $

DISTNAME=	Sil-130-src
PKGNAME=	sil-1.3.0
CATEGORIES=	games
MASTER_SITES=	http://www.amirrorclear.net/flowers/game/sil/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.amirrorclear.net/flowers/game/sil/index.html
COMMENT=	Roguelike that stays true to the writing of Tolkien
LICENSE=	gnu-gpl-v2 OR angband

WRKSRC=	${WRKDIR}/Sil/src

USE_TOOLS+=	gmake
USE_GAMESGROUP=	yes

MAKE_FILE=	Makefile.std

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/Sil
INSTALLATION_DIRS+=	share/Sil
INSTALLATION_DIRS+=	share/Sil/apex
INSTALLATION_DIRS+=	share/Sil/edit
INSTALLATION_DIRS+=	share/Sil/pref
INSTALLATION_DIRS+=	share/Sil/xtra
INSTALLATION_DIRS+=	share/Sil/xtra/font
INSTALLATION_DIRS+=	share/Sil/xtra/graf
INSTALLATION_DIRS+=	share/Sil/xtra/sound

OWN_DIRS_PERMS+=	${PREFIX}/share/Sil/data ${GAMEDIR_PERMS}
REQD_FILES_PERMS+=	/dev/null ${PREFIX}/share/Sil/apex/scores.raw ${GAMEDATA_PERMS}
SPECIAL_PERMS+=		${PREFIX}/bin/sil ${SETGID_GAMES_PERMS}

CFLAGS+=		-DDEFAULT_PATH='\"${PREFIX}/share/Sil\"'
CFLAGS+=		-DPRIVATE_USER_PATH
CFLAGS+=		-DUSE_PRIVATE_SAVE_PATH
CFLAGS+=		-DUSE_X11 -DUSE_GCU

BUILD_MAKE_FLAGS=	CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_GAME} ${WRKSRC}/sil ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} "${WRKDIR}/Sil/Sil 1.3 Manual.pdf" "${DESTDIR}${PREFIX}/share/doc/Sil/Sil Manual.pdf"
	for d in apex edit pref xtra; do \
		cd ${WRKDIR}/Sil/lib && ${FIND} $$d -type f ! -name .DS_Store | while read f; do \
			${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/Sil/$${f%/*} || exit 1; \
		done; \
	done

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
