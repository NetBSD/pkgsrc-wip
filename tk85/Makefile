# $NetBSD: Makefile,v 1.3 2011/06/07 23:05:30 asau Exp $

DISTNAME=	tk${TK_VERSION}-src
PKGNAME=	tk-${TK_VERSION}
CATEGORIES=	x11 lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Graphical toolkit for TCL

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/tk85/Makefile.version"

WRKSRC=			${WRKDIR}/tk${TK_VERSION}

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib/tcl${TCL_VERSION:C/.[0-9]*$//}

TEST_TARGET=		test
INSTALL_TARGET=		install install-private-headers

.include "../../wip/tcl85/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

DESTDIRPREFIX=		${DESTDIR}${PREFIX}

post-install:
	rm -f ${DESTDIRPREFIX:Q}/bin/wish
	ln -s wish${TK_VERSION:C/.[0-9]*$//} ${DESTDIRPREFIX:Q}/bin/wish
	mv ${DESTDIRPREFIX:Q}/lib/tkConfig.sh ${DESTDIRPREFIX:Q}/lib/tk${TK_VERSION:C/.[0-9]*$//}

.include "../../mk/bsd.pkg.mk"
