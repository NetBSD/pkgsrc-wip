# $NetBSD: Makefile,v 1.9 2012/10/22 23:04:57 othyro Exp $

DISTNAME=		tk8.6b2-src.tar.gz
PKGNAME=		tk86-${TK_PKGSRC_PATCHLEVEL}
CATEGORIES=		x11 lang
MASTER_SITES=		http://sourceforge.net/projects/tcl/files/Tcl/8.6b2/

MAINTAINER=		bch@methodlogic.net
HOMEPAGE=		http://www.tcl.tk/
EXTRACT_SUFX=
EXTRACT_CMD=		tar xzf $$extract_file
COMMENT=		Graphical toolkit for Tcl
LICENSE=		2-clause-bsd # ?

.include "../../wip/tk86/Makefile.version"
.include "../../wip/tcl86/options.mk"

WRKSRC=			${WRKDIR}/tk8.6b2

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	unix
BUILD_DIRS=		${CONFIGURE_DIRS}
USE_TOOLS+=		tar

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
	${RM} ${DESTDIRPREFIX:Q}/lib/tk8.6/demos/license.terms

.include "../../mk/bsd.pkg.mk"
