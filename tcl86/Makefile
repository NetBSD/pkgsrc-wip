# $NetBSD: Makefile,v 1.4 2010/12/31 19:55:18 bharder Exp $
#

DISTNAME=		tcl${TCL_PKGSRC_PATCHLEVEL}-src
PKGNAME=		tcl86-${TCL_PKGSRC_PATCHLEVEL}
CATEGORIES=		lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=		bch@methodlogic.net
HOMEPAGE=		http://www.tcl.tk/
COMMENT=		Tool Command Language, a dynamic language

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/tcl86/Makefile.version"
.include "options.mk"

CONFLICTS+=		tclman80-[0-9]*
CONFLICTS+=		tcl85-* tcl-[0-9]*

WRKSRC=			${WRKDIR}/tcl${TCL_PKGSRC_PATCHLEVEL}

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
CONFIGURE_DIRS=	unix
BUILD_DIRS=		${CONFIGURE_DIRS}

CONFIGURE_ARGS+=	"--prefix=${PREFIX}"
# CONFIGURE_ARGS+=	"--enable-shared=off"
# CONFIGURE_ARGS+=	"--libexecdir=${PREFIX}/tcl${TCL_PKGSRC_PATCHLEVEL}"
# CONFIGURE_ARGS+=	"--libdir=${PREFIX}/lib/tcl${TCL_PKGSRC_PATCHLEVEL}"
# CONFIGURE_ARGS+=	"--includedir=${PREFIX}/include/tcl${TCL_PKGSRC_PATCHLEVEL}"
# CONFIGURE_ARGS+=	"--mandir=${PREFIX}/tcl${TCL_PKGSRC_PATCHLEVEL}/man"

INSTALL_TARGET=	install install-private-headers

# The test target gives better results when not run as root.
TEST_TARGET=		test


# This is needed for SGI and maybe sun (according to tcl developers)
.if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

DESTDIRPREFIX=          ${DESTDIR}${PREFIX}

post-install:	
	cp ${WRKSRC}/doc/man.macros ${DESTDIRPREFIX:Q}/man/mann
#	mkdir -p ${DESTDIRPREFIX:Q}/lib/tcl${TCL_PKGSRC_VERSION}
#	mv ${DESTDIRPREFIX:Q}/lib/tclConfig.sh ${DESTDIRPREFIX:Q}/lib/tcl${TCL_PKGSRC_VERSION}

CVS_REPOSITORIES=	tcl
CVS_ROOT.tcl=		:pserver:anonymous:@tcl.cvs.sourceforge.net:/cvsroot/tcl
WRKSRC=			${WRKDIR}/tcl
CHECKOUT_DATE=		2010-12-31

.include "../mk/cvs-package.mk"

.include "../../mk/bsd.pkg.mk"
