# $NetBSD$

DISTNAME=	df_44_02_linux
PKGNAME=	dwarf_fortress-44.02
CATEGORIES=	games
MASTER_SITES=	http://www.bay12games.com/dwarves/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bay12games.com/dwarves/
COMMENT=	Single-player fantasy game in a randomly generated, persistent world
LICENSE=	unlicense

#UNPRIVILEGED= yes

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	base compat expat gtk2 png libSDL glx x11 locale

NO_BUILD=	yes
USE_TOOLS+=	pax
BUILD_DIRS=	# empty
WRKSRC=		${WRKDIR}/df_linux

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTFILES=	${DISTNAME}32${EXTRACT_SUFX}
.elif ${EMUL_PLATFORM} == "linux-x86_64"
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.endif

INSTALLATION_DIRS=	bin df_linux

AUTO_MKDIRS=	yes
DFDIR=		df_linux

post-extract:
	${RM} -r ${WRKDIR}/${DFDIR}/g_src

#post-install:
#	${CP} ${WRKSRC}/df ${DESTDIR}${PREFIX}/bin/df_linux

pre-install:
	${RM}	${WRKDIR}/${DFDIR}/df.orig
	${INSTALL_SCRIPT}	${WRKDIR}/df_linux/df	${DESTDIR}${PREFIX}/bin/df_linux
	cd ${WRKSRC} && pax -rw ./ ${DESTDIR}${PREFIX}/df_linux

# png no longer seems to be broken.
#
#SUBST_CLASSES+= fix-paths
#SUBST_MESSAGE.fix-paths= Fixing pngs to bmps.
#SUBST_STAGE.fix-paths= post-configure
#SUBST_FILES.fix-paths= libs/Dwarf_Fortress
#SUBST_FILES.fix-paths+= data/init/init.txt
#SUBST_SED.fix-paths= -e 's,\.png,.bmp,g'


# Need import SUSE OpenAL
#
SUBST_CLASSES+=			fix-paths-1
SUBST_MESSAGE.fix-paths-1=	Disabling sound.
SUBST_STAGE.fix-paths-1=	post-configure
SUBST_FILES.fix-paths-1=	data/init/init.txt
SUBST_SED.fix-paths-1=		-e 's,SOUND:YES,SOUND:NO,g'

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
