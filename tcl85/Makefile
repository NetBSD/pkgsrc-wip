# $NetBSD: Makefile,v 1.3 2010/07/31 20:17:35 bharder Exp $
#

DISTNAME=		tcl${TCL_PKGSRC_PATCHLEVEL}-src
PKGNAME=		tcl-${TCL_PKGSRC_PATCHLEVEL}
CATEGORIES=		lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tcl.tk/
COMMENT=		Tool Command Language, a dynamic language

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/tcl85/Makefile.version"
.include "options.mk"

CONFLICTS+=		tclman80-[0-9]*

WRKSRC=			${WRKDIR}/tcl${TCL_PKGSRC_PATCHLEVEL}

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	unix
BUILD_DIRS=		${CONFIGURE_DIRS}

CONFIGURE_ARGS+=	"--prefix=${PREFIX}"
INSTALL_TARGET=	install install-private-headers

# The test target gives better results when not run as root.
TEST_TARGET=		test


# This is needed for SGI and maybe sun (according to tcl developers)
.if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

DESTDIRPREFIX=          ${DESTDIR}${PREFIX}

post-install:
	mv ${DESTDIRPREFIX:Q}/lib/tclConfig.sh ${DESTDIRPREFIX:Q}/lib/tcl${TCL_PKGSRC_VERSION}
	cd ${DESTDIR:Q}${PREFIX:Q}/bin && ln -s tclsh8.5 tclsh

.include "../../mk/bsd.pkg.mk"
