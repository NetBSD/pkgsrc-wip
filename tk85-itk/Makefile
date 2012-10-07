# $NetBSD: Makefile,v 1.2 2012/10/07 17:17:37 asau Exp $
#

DISTNAME=	itk3.3
PKGNAME=	tk85-${DISTNAME:S/k/k-/}
CATEGORIES=	devel
MASTER_SITES=	http://sourceforge.net/projects/incrtcl/files/%5BIncr%20Tcl_Tk%5D-source/3.3-RC/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incrtcl.sourceforge.net/itk/index.html
COMMENT=	Framework for building mega-widgets using [incr Tcl]
LICENSE=	2-clause-bsd # ?

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib/tcl8.5
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib/tk8.5
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11}/include/X11
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libX11}/lib
USE_TOOLS+=		grep

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../wip/tcl85-itcl/buildlink3.mk"
.include "../../wip/tcl85/buildlink3.mk"
.include "../../wip/tk85/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
