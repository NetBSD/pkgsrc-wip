# $NetBSD$

VERS=		1.47.2
#PKGNAME=	doomlegacy-${VERS}
SVNVERS=	1448
DISTNAME=	doomlegacy-devel-r${SVNVERS}
CATEGORIES=	games

DISTFILES=			doomlegacy_${VERS}_common.zip
MASTER_SITES=			${MASTER_SITE_SOURCEFORGE:=doomlegacy/}
SVN_REPOSITORIES=		legacy_one
SVN_REPO.legacy_one=		svn://svn.code.sf.net/p/doomlegacy/svn/legacy_one/trunk
SVN_REVISION.legacy_one=	${SVNVERS}
SVN_EXTRACTDIR.legacy_one=	doomlegacy-devel-r${SVNVERS}

MAINTAINER=		micha@NetBSD.org
HOMEPAGE=		http://doomlegacy.sourceforge.net/
COMMENT=		The legacy of Doom
LICENSE=		gnu-gpl-v2

# Tested on Linux/ppc (32bit Big Endian) and NetBSD/amd64 (64bit Little Endian)
# Untested: In general the source code has support for the other listed OS too
ONLY_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-* \
			NetBSD-*-* OpenBSD-*-* SunOS-*-*

USE_LANGUAGES+=		c99

USE_TOOLS+=		gmake
MAKE_JOBS_SAFE=		no

.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/endian.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
MAKE_FLAGS+=		OS=FREEBSD
.elif ${OPSYS} == "NetBSD"
MAKE_FLAGS+=		OS=NETBSD
.elif ${OPSYS} == "Darwin"
MAKE_FLAGS+=		OS=MAC
.else
# Other Unix (should work for GNU/Linux, OpenBSD and SunOS)
MAKE_FLAGS+=		OS=LINUX
.endif

.if ${MACHINE_ENDIAN} == "big"
# Some compilers define this themselves (but maybe not all)
CFLAGS+=		-D__BIG_ENDIAN__
.endif

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6 share/doc/doomlegacy ${DOOMWADDIR}

MESSAGE_SRC+=		MESSAGE.doomlegacy
MESSAGE_SUBST+=		PKGNAME=${PKGNAME:C/-.*//}
MESSAGE_SUBST+=		DOOMWADDIR_CONF="${PREFIX}/${DOOMWADDIR}"

# Configure to honor environment
SUBST_CLASSES+=		makeopt
SUBST_STAGE.makeopt=	do-configure
SUBST_MESSAGE.makeopt=	Preparing make_options file ...
SUBST_FILES.makeopt=	make_options
SUBST_SED.makeopt=	-e 's,\#COMP_ENVIRONMENT,COMP_ENVIRONMENT,'

# Configure defaults for LEGACYWADDIR and DOOMWADDIR
SUBST_CLASSES+=		doomdef
SUBST_STAGE.doomdef=	do-configure
SUBST_MESSAGE.doomdef=	Preparing doomdef.h file ...
SUBST_FILES.doomdef=	src/doomdef.h
SUBST_SED.doomdef=	-e 's,LEGACYWADDIR  "/usr/local/share/games/doomlegacy",LEGACYWADDIR  "${PREFIX}/${DOOMWADDIR}",g'
SUBST_SED.doomdef+=	-e 's,DEFWADS01  "~/games/doomlegacy/wads",DEFWADS01  "${PREFIX}/${DOOMWADDIR}",'

pre-configure:
	${CP} ${FILESDIR}/doomlegacy.6.in ${WRKDIR}
	cd ${WRKSRC} && ${CP} make_options_nix make_options

# Move configure options and process manpage template
do-configure:
	cd ${WRKDIR} &&							\
		${SED} -e 's,$$NAME,doomlegacy,g'			\
			-e 's,$$VERSION,${VERS},g'			\
			-e 's,$$WADDIR,${PREFIX}/${DOOMWADDIR},g'	\
			doomlegacy.6.in >doomlegacy.6

do-install:
	cd ${WRKSRC} &&							\
		${INSTALL_PROGRAM} bin/doomlegacy			\
			${DESTDIR}${PREFIX}/bin;			\
		${INSTALL_DATA} docs/legacy.css docs/whatsnew.html	\
			${DESTDIR}${PREFIX}/share/doc/doomlegacy;	\
	cd ${WRKDIR}/doomlegacy_${VERS} &&				\
		${INSTALL_DATA} legacy.wad				\
			${DESTDIR}${PREFIX}/${DOOMWADDIR}/legacy.wad;	\
	cd ${WRKDIR} &&							\
		${INSTALL_MAN} ${WRKDIR}/doomlegacy.6			\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

# Ensure that at least the shareware Episode 1 of Doom is available
# Note: The demos from games/doom1 are not compatible with the Legacy engine
DEPENDS+=		doom1-[0-9]*:../../games/doom1

BUILDLINK_API_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.7
.include "../../audio/SDL_mixer/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL+=		SDL>=1.2.10
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
