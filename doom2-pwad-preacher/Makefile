# $NetBSD$

DISTNAME=		preacher
# Use release date from preacher.txt as package version
PKGNAME=		doom2-pwad-${DISTNAME}-20181129
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.fu-berlin.de/pc/games/idgames/levels/doom2/Ports/p-r/
EXTRACT_SUFX=		.zip

MAINTAINER=		micha@NetBSD.org
COMMENT=		Doom II mod
LICENSE=		preacher-license

.include "../../mk/bsd.prefs.mk"

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	${DOOMWADDIR}

NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	cd ${WRKDIR} &&							\
		${INSTALL_DATA} PREACHER.wad				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/PREACHER.wad;	\
		${INSTALL_DATA} preacher.txt				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/PREACHER.txt

.include "../../mk/bsd.pkg.mk"
