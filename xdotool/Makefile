# $NetBSD: Makefile,v 1.1.1.1 2011/01/02 05:42:34 rubengonzalez Exp $
#

DISTNAME=	xdotool-2.20101012.3049
PKGNAME=	xdotool-2.20101012
PKGREVISION=    1
CATEGORIES=     x11
MASTER_SITES=	http://semicomplete.googlecode.com/files/

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://www.semicomplete.com/projects/xdotool/
COMMENT=	Simulate keyboard input and mouse activity using X11 xtest extension

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=   yes
USE_LIBTOOL=    yes
USE_TOOLS+=	gmake
USE_TOOLS+=     pkg-config

.include "../../lang/perl5/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
