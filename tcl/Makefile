# $NetBSD: Makefile,v 1.1.1.1 2008/07/22 20:31:07 asau Exp $

DISTNAME=	tcl${TCL_VERSION}-src
PKGNAME=	tcl-${TCL_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Ousterhout's Tool Command Language, a dynamic language

.include "../../wip/tcl/Makefile.version"

CONFLICTS+=		tclman80-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/tcl${TCL_VERSION}

# Tcl developers strives to get compiler/linker flags correct.
# If on some platform pkgsrc supports they are not right,
# please fill a bug with tcl developers.
#USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
MAKE_ENV+=		TOUCH=${TOUCH:Q}

CONFIGURE_ARGS+=	"--prefix=${PREFIX}"

INSTALL_TARGET=		install

# The test target gives better results when not run as root.
TEST_TARGET=		test
#TEST_ENV+=		TZ=+0

.include "../../mk/bsd.prefs.mk"

# This should be a compile option. Default is still "disabled"
# for un*x systems. We belive the developers
#.if ${OPSYS} == "NetBSD"
#.  if empty(OS_VERSION:M1.[56]*)
#CONFIGURE_ARGS+=	--enable-threads
#.  else
#CONFIGURE_ARGS+=	--disable-threads
#.  endif
#.endif

# Add ${VIEWBASE}/lib/tcl to the list of locations for Tcl packages.
CONFIGURE_ENV+=		TCL_PACKAGE_PATH="${VIEWBASE}/lib/tcl"

.if ${OPSYS} == "NetBSD"
.  if empty(OS_VERSION:M1.[56]*)
.    include "../../mk/pthread.buildlink3.mk"
.  endif
.endif

# This is needed for SGI and maybe sun (according to tcl developers)
.if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

SUBST_CLASSES+=		tcl-config
SUBST_STAGE.tcl-config=	post-build
SUBST_FILES.tcl-config=	unix/tclConfig.sh
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tcl|"

INSTALLATION_DIRS+=	include/tcl
INSTALLATION_DIRS+=	include/tcl/unix
INSTALLATION_DIRS+=	include/tcl/generic
INSTALLATION_DIRS+=	lib/tcl

# don't link tclsh8.5 to tclsh until this version becomes the default
post-install:
	#cd ${DESTDIR:Q}${PREFIX:Q}/lib && mv tclConfig.sh-s tclsh8.5 tclsh
	${INSTALL_DATA} ${WRKSRC}/unix/tclUnixPort.h \
		${DESTDIR:Q}${PREFIX:Q}/include/tcl/unix
.for f in	regex.h tcl.h tclCompile.h tclDecls.h tclIO.h		\
		tclInt.h tclIntDecls.h tclIntPlatDecls.h\
		tclPlatDecls.h tclPort.h tclRegexp.h
	${INSTALL_DATA} ${WRKSRC}/generic/${f} \
		${DESTDIR:Q}${PREFIX:Q}/include/tcl/generic
.endfor

.include "../../mk/bsd.pkg.mk"
