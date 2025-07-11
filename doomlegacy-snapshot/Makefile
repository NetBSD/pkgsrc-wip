# $NetBSD$

VERS=		1.48.16
#PKGNAME=	doomlegacy-${VERS}
SVNVERS=	1750
DISTNAME=	doomlegacy-snapshot-0r${SVNVERS}
CATEGORIES=	games

DISTFILES=			doomlegacy_${VERS}_common.zip
MASTER_SITES=			${MASTER_SITE_SOURCEFORGE:=doomlegacy/}
SVN_REPOSITORIES=		legacy_one
SVN_REPO.legacy_one=		svn://svn.code.sf.net/p/doomlegacy/svn/legacy_one/trunk
SVN_REVISION.legacy_one=	${SVNVERS}
SVN_EXTRACTDIR.legacy_one=	doomlegacy-snapshot-0r${SVNVERS}

MAINTAINER=		micha@NetBSD.org
HOMEPAGE=		http://doomlegacy.sourceforge.net/
COMMENT=		The legacy of Doom
LICENSE=		gnu-gpl-v2

CONFLICTS+=		doomlegacy-[0-9]*

#GCC_REQD+=		10

# Tested on Linux/ppc (32bit Big Endian) and NetBSD/amd64 (64bit Little Endian)
# Untested: In general the source code has support for the other listed OS too
ONLY_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-* \
			NetBSD-*-* OpenBSD-*-* SunOS-*-*

USE_CC_FEATURES+=	c99

USE_TOOLS+=		gmake
# Dependency generation fails with parallel build
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
CFLAGS.SunOS+=		-DSOLARIS
LDFLAGS.SunOS+=		-lresolv -lsocket -lnsl
.endif

.if ${MACHINE_ENDIAN} == "big"
# Some compilers define this themselves (but maybe not all)
CFLAGS+=		-D__BIG_ENDIAN__
.endif

# Required by extended node patch for ZDoom compressed node format
CFLAGS+=		-DHAVE_ZLIB
LDFLAGS+=		-lz

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6 share/doc/doomlegacy ${DOOMWADDIR}

# Configure to honor environment and disable ZIP support on GNU/Linux
# Use native CPU architecture
SUBST_CLASSES+=		makeopt
SUBST_STAGE.makeopt=	do-configure
SUBST_MESSAGE.makeopt=	Preparing make_options file ...
SUBST_FILES.makeopt=	make_options
SUBST_SED.makeopt=	-e 's,\#[ ]*COMP_ENVIRONMENT,COMP_ENVIRONMENT,'
SUBST_SED.makeopt+=	-e 's,HAVE_LIBZIP,\# HAVE_LIBZIP,'
SUBST_SED.makeopt+=	-e 's,HAVE_DLOPEN,\# HAVE_DLOPEN,'
SUBST_SED.makeopt+=	-e 's,\# ARCH=-march=native,ARCH=-march=native,'
SUBST_SED.makeopt+=	-e 's,ARCH=-march=i686,\# ARCH=-march=native,'
# Enable debug build
#SUBST_SED.makeopt+=	-e 's,\# DEBUG=1,DEBUG=1,'

# Add debug symbols only (less performance impact than DEBUG build above)
CFLAGS+=		-g
INSTALL_UNSTRIPPED=	yes

# Configure defaults for LEGACYWADDIR and DOOMWADDIR
SUBST_CLASSES+=		doomdef
SUBST_STAGE.doomdef=	do-configure
SUBST_MESSAGE.doomdef=	Preparing doomdef.h file ...
SUBST_FILES.doomdef=	src/doomdef.h
SUBST_SED.doomdef=	-e 's,LEGACYWADDIR  "/usr/local/share/games/doomlegacy",LEGACYWADDIR  "${PREFIX}/${DOOMWADDIR}",g'
SUBST_SED.doomdef+=	-e 's,DEFWADS01  "~/games/doomlegacy/wads",DEFWADS01  "${PREFIX}/${DOOMWADDIR}",'

# Configure INSTALL.pkgsrc (formerly displayed as MESSAGE)
SUBST_CLASSES+=		install
SUBST_STAGE.install=	do-configure
SUBST_MESSAGE.install=	Preparing INSTALL.pkgsrc file ...
SUBST_FILES.install=	${WRKDIR}/INSTALL.pkgsrc
SUBST_SED.install=	-e 's,DOOMWADDIR,${PREFIX}/${DOOMWADDIR},'

pre-configure:
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKDIR}
	${CP} ${FILESDIR}/doomlegacy.sh ${WRKDIR}
	${CP} ${FILESDIR}/doomlegacy.6.in ${WRKDIR}
	cd ${WRKSRC} && ${CP} make_options_nix make_options

# Move configure options and process manpage template
do-configure:
	cd ${WRKDIR} && ${SED} -e 's,$$PREFIX,${PREFIX},'		\
		 doomlegacy.sh >doomlegacy
	cd ${WRKDIR} && ${SED} -e 's,$$NAME,doomlegacy,g'		\
		-e 's,$$VERSION,${VERS},g'				\
		-e 's,$$WADDIR,${PREFIX}/${DOOMWADDIR},g'		\
		doomlegacy.6.in >doomlegacy.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doomlegacy			\
		${DESTDIR}${PREFIX}/bin/doomlegacy.bin
	${INSTALL_SCRIPT} ${WRKDIR}/doomlegacy				\
		${DESTDIR}${PREFIX}/bin/doomlegacy
	${INSTALL_DATA} ${WRKDIR}/doomlegacy_${VERS}_common/dogs.wad	\
		${DESTDIR}${PREFIX}/${DOOMWADDIR}/dogs.wad
	${INSTALL_DATA} ${WRKDIR}/doomlegacy_${VERS}_common/legacy.wad	\
		${DESTDIR}${PREFIX}/${DOOMWADDIR}/legacy.wad
	cd ${WRKSRC} &&							\
		${INSTALL_DATA} docs/legacy.css docs/whatsnew.html	\
			${DESTDIR}${PREFIX}/share/doc/doomlegacy
	${INSTALL_DATA} ${WRKDIR}/INSTALL.pkgsrc			\
		${DESTDIR}${PREFIX}/share/doc/doomlegacy/INSTALL.pkgsrc
	${INSTALL_MAN} ${WRKDIR}/doomlegacy.6				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6


# Ensure that at least the shareware Episode 1 of Doom is available
DEPENDS+=		doom1-[0-9]*:../../games/doom1

BUILDLINK_API_DEPENDS.zlib+=			zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL_mixer+=		SDL_mixer>=1.2.7
.include "../../audio/SDL_mixer/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL+=			SDL>=1.2.10
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
