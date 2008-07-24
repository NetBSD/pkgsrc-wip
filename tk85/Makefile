# $NetBSD: Makefile,v 1.1.1.1 2008/07/24 19:35:09 egavilan Exp $

DISTNAME=		tk${TK_PKGSRC_PATCHLEVEL}-src
PKGNAME=		tk-${TK_PKGSRC_PATCHLEVEL}
CATEGORIES=		x11 lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tcl.tk/
COMMENT=		Graphical toolkit for Tcl

.include "../../wip/tk85/Makefile.version"

WRKSRC=			${WRKDIR}/tk${TK_PKGSRC_PATCHLEVEL}

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	unix
BUILD_DIRS=		${CONFIGURE_DIRS}

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib/tcl${TCL_PKGSRC_VERSION}

TEST_TARGET=	test
INSTALL_TARGET=	install install-private-headers

.include "../../wip/tcl85/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

DESTDIRPREFIX=		${DESTDIR}${PREFIX}

post-install:
	mv ${DESTDIRPREFIX:Q}/lib/tkConfig.sh ${DESTDIRPREFIX:Q}/lib/tk${TK_PKGSRC_VERSION}

.include "../../mk/bsd.pkg.mk"
