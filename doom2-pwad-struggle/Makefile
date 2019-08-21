# $NetBSD$

DISTNAME=		strg
# Use release date from STRG.txt as package version
PKGNAME=		doom2-pwad-struggle-20180819
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.fu-berlin.de/pc/games/idgames/levels/doom2/Ports/megawads/
MASTER_SITES+=		ftp://mirrors.syringanetworks.net/idgames/levels/doom2/Ports/megawads/
EXTRACT_SUFX=		.zip

MAINTAINER=		micha@NetBSD.org
COMMENT=		Doom II mod
LICENSE=		cc-by-nc-v4.0

.include "../../mk/bsd.prefs.mk"

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	${DOOMWADDIR}

MESSAGE_SRC+=		MESSAGE.doom2-pwad-struggle
MESSAGE_SUBST+=		DOOMWADDIR="${PREFIX}/${DOOMWADDIR}"

NO_BUILD=		yes

do-install:
	cd ${WRKDIR} &&							\
		${INSTALL_DATA} STRG.wad				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/STRG.wad;	\
		${INSTALL_DATA} STRG_M28.wad				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/STRG_M28.wad;	\
		${INSTALL_DATA} STRG.txt				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/STRG.txt

.include "../../mk/bsd.pkg.mk"
