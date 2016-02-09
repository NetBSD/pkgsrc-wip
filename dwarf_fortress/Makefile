# $NetBSD: Makefile,v 1.2 2015/05/08 22:58:43 i3enedek Exp $

DISTNAME=	df_42_05_linux
PKGNAME=	dwarf_fortress-42.05
CATEGORIES=	games
MASTER_SITES=	http://www.bay12games.com/dwarves/
EXTRACT_SUFX=	.tar.bz2
LICENSE=	unlicense

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bay12games.com/dwarves/
COMMENT=	Single-player fantasy game in a randomly generated, persistent world

UNPRIVILEGED= yes

NO_BUILD=	yes
BUILD_TOOLS=    pax
BUILD_DIRS=     # empty
WRKSRC=		${WRKDIR}/df_linux

INSTALLATION_DIRS=bin df_linux
#INSTALLATION_DIRS=bin df_linux/data df_linux/data/movies df_linux/data/art df_linux/data/init df_linux/data/init/macros df_linux/data/announcement df_linux/data/dipscript df_linux/data/dipscript/text df_linux/data/help df_linux/data/speech df_linux/data/initial_movies df_linux/data/sound df_linux/raw df_linux/raw/graphics df_linux/raw/graphics/example df_linux/raw/interaction\ examples df_linux/raw/objects df_linux/raw/objects/notes df_linux/raw/objects/text df_linux/sdl df_linux/libs

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base compat expat gtk2 libSDL glx x11

DFDIR=        df_linux

PREFIX=	#empty	
do-install:

	${RM} -r ${WRKDIR}/${DFDIR}/g_src
	#cd ${DESTDIR} && ${MKDIR} bin df_linux/data df_linux/data/movies df_linux/data/art df_linux/data/init df_linux/data/init/macros df_linux/data/announcement df_linux/data/dipscript df_linux/data/dipscript/text df_linux/data/help df_linux/data/speech df_linux/data/initial_movies df_linux/data/sound df_linux/raw df_linux/raw/graphics df_linux/raw/graphics/example df_linux/raw/interaction\ examples df_linux/raw/objects df_linux/raw/objects/notes df_linux/raw/objects/text df_linux/sdl df_linux/libs  
	#cd ${WRKSRC} && find ./data -exec chmod 666 {} \;
	#cd ${WRKSRC} && find ./raw -exec chmod 666 {} \;
	#cd ${WRKSRC} && find . -type d -exec chmod 755 {} \;
	#cd ${WRKSRC} && find . -maxdepth 1 -type f -exec chmod 666 {} \;
	${CP} ${WRKDIR}/df_linux/df ${DESTDIR}${PREFIX}/bin/df_linux
	cd ${WRKSRC} && pax -rw ./ ${DESTDIR}${PREFIX}/df_linux
SUBST_CLASSES+= fix-paths
SUBST_SKIP_TEXT_CHECK.fix-paths= yes
SUBST_MESSAGE.fix-paths= Fixing pngs to bmps.
SUBST_STAGE.fix-paths= post-configure
SUBST_FILES.fix-paths= libs/Dwarf_Fortress
SUBST_FILES.fix-paths+= data/init/init.txt
SUBST_SED.fix-paths= -e 's,\.png,.bmp,g'

SUBST_CLASSES+= fix-paths-1
SUBST_MESSAGE.fix-paths= Disabling sound.
SUBST_STAGE.fix-paths-1= post-configure
SUBST_FILES.fix-paths-1= data/init/init.txt
SUBST_SED.fix-paths-1= -e 's,SOUND:YES,SOUND:NO,g'

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
