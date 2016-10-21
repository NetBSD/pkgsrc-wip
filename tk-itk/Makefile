# $NetBSD: Makefile,v 1.8 2014/02/22 08:25:04 obache Exp $
#

DISTNAME=	itk3.4.2
PKGNAME=	tk-${DISTNAME:S/itk/itk3-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=incrtcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incrtcl.sourceforge.net/
COMMENT=	Framework for building mega-widgets for Tcl/Tk
LICENSE=	mit # Standard ML of New Jersey Variant

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11}/include/X11
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libX11}/lib
CONFIGURE_ARGS+=	--with-itcl=${BUILDLINK_PREFIX.tcl-itcl3}/lib

USE_TOOLS+=		grep

WRKSRC=		${WRKDIR}/${DISTNAME:R}

.include "../../wip/tcl-itcl3/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
