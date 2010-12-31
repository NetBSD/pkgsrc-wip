# $NetBSD: Makefile,v 1.4 2010/12/31 19:56:29 bharder Exp $

DISTNAME=		tk${TK_PKGSRC_PATCHLEVEL}-src
PKGNAME=		tk86-${TK_PKGSRC_PATCHLEVEL}
CATEGORIES=		x11 lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=		bch@methodlogic.net
HOMEPAGE=		http://www.tcl.tk/
COMMENT=		Graphical toolkit for Tcl

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/tk86/Makefile.version"
.include "../../wip/tcl86/options.mk"

WRKSRC=			${WRKDIR}/tk${TK_PKGSRC_PATCHLEVEL}

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	unix
BUILD_DIRS=		${CONFIGURE_DIRS}

CONFIGURE_ARGS+=	--prefix=${PREFIX}
# CONFIGURE_ARGS+=	--with-tcl=${TCLCONFIG_SH_DIR}
CONFIGURE_ARGS+=	--with-tcl=${PREFIX}/lib
# CONFIGURE_ARGS+=	--enable-shared=no

TEST_TARGET=	test
INSTALL_TARGET=	install install-private-headers

.include "../../wip/tcl86/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

DESTDIRPREFIX=		${DESTDIR}${PREFIX}

post-install:
	mv ${DESTDIRPREFIX:Q}/lib/tkConfig.sh ${DESTDIRPREFIX:Q}/lib/tk${TK_PKGSRC_VERSION}

CVS_REPOSITORIES=	tk
CVS_ROOT.tk=	:pserver:anonymous:@tktoolkit.cvs.sourceforge.net:/cvsroot/tktoolkit
WRKSRC=			${WRKDIR}/tk
CHECKOUT_DATE=		2010-12-31

.include "../mk/cvs-package.mk"

.include "../../mk/bsd.pkg.mk"
