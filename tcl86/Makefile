# $NetBSD: Makefile,v 1.5 2011/03/29 22:17:56 bharder Exp $
#

DISTNAME=		999804376c
PKGNAME=		tcl86-${TCL_PKGSRC_PATCHLEVEL}
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://mirror1.tcl.tk/tcl/tarball/tcl.tgz?uuid=
EXTRACT_SUFX=
EXTRACT_CMD=		tar xzf $$extract_file

MAINTAINER=		bch@methodlogic.net
HOMEPAGE=		http://www.tcl.tk/
COMMENT=		Tool Command Language, a dynamic language

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/tcl86/Makefile.version"
.include "options.mk"

CONFLICTS+=		tclman80-[0-9]*
CONFLICTS+=		tcl85-* tcl-[0-9]*

WRKSRC=			${WRKDIR}/tcl.tgz

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


.include "../../mk/bsd.pkg.mk"
