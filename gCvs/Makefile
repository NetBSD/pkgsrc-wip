# $NetBSD: Makefile,v 1.1.1.1 2003/08/12 13:06:43 adrian_p Exp $

DISTNAME=	gcvs-1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cvsgui/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://cvsgui.sourceforge.net/index.html
COMMENT=	GUI frontend to CVS

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-gtk
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tcllib=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tclinclude=${BUILDLINK_PREFIX.tcl}/include

.include "../../x11/gtk/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
