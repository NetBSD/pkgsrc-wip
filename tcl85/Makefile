# $NetBSD: Makefile,v 1.10 2012/10/07 17:17:26 asau Exp $

DISTNAME=	tcl${TCL_VERSION}-src
PKGNAME=	tcl-${TCL_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Tool Command Language, a dynamic language

CONFLICTS+=	tclman80-[0-9]*
CONFLICTS+=	tcl86-* tcl-[0-9]*

.include "../../wip/tcl85/Makefile.version"

WRKSRC=			${WRKDIR}/tcl${TCL_VERSION}

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
INSTALL_TARGET=	install install-private-headers

# The test target gives better results when not run as root.
TEST_TARGET=		test

.include "options.mk"

# This is needed for SGI and maybe sun (according to tcl developers)
.if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

DESTDIRPREFIX=          ${DESTDIR}${PREFIX}

post-install:
	cd ${DESTDIRPREFIX:Q}/bin && ln -s tclsh8.5 tclsh
	mv ${DESTDIRPREFIX:Q}/lib/tclConfig.sh ${DESTDIRPREFIX:Q}/lib/tcl${TCL_VERSION:C/.[0-9]*$//}

.include "../../mk/bsd.pkg.mk"
