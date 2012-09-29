# $NetBSD: Makefile,v 1.1 2012/09/29 02:11:01 othyro Exp $
#

DISTNAME=	itcl3.4.1
PKGNAME=	${DISTNAME:S/itcl/tcl85-itcl-/}
CATEGORIES=	devel
MASTER_SITES=	http://sourceforge.net/projects/incrtcl/files/%5BIncr%20Tcl_Tk%5D-source/3.4.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incrtcl.sourceforge.net/
COMMENT=	O-O system for Tcl
LICENSE=	2-clause-bsd # ?

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib/tcl8.5 \
			--with-tk=${BUILDLINK_PREFIX.tk}/lib/tk8.5

pre-install:
		${MV} ${WRKSRC}/doc/class.n ${WRKSRC}/doc/itcl-class.n

.include "../../wip/tcl-tclOO/buildlink3.mk"
.include "../../wip/tk85/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
