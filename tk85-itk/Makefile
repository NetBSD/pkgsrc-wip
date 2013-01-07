# $NetBSD: Makefile,v 1.7 2013/01/07 13:30:24 thomasklausner Exp $
#

DISTNAME=	itk3.3
PKGNAME=	tk-${DISTNAME:S/k/k-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=incrtcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incrtcl.sourceforge.net/itk/index.html
COMMENT=	Framework for building mega-widgets using [incr Tcl]
LICENSE=	2-clause-bsd # ?

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11}/include/X11
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libX11}/lib
USE_TOOLS+=		grep

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../lang/tcl-itcl/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
