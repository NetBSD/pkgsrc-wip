# $NetBSD: Makefile,v 1.4 2012/10/23 10:28:55 thomasklausner Exp $
#

DISTNAME=	xdotool-2.20110530.1
CATEGORIES=     x11
MASTER_SITES=	http://semicomplete.googlecode.com/files/

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://www.semicomplete.com/projects/xdotool/
COMMENT=	Simulate keyboard input and mouse activity using X11 xtest extension

NO_CONFIGURE=   yes
USE_LIBTOOL=    yes
USE_TOOLS+=	gmake
USE_TOOLS+=     pkg-config

SUBST_CLASSES+=           fix-getopt
SUBST_STAGE.fix-getopt=   pre-build
SUBST_MESSAGE.fix-getopt= Fixing getopt
SUBST_FILES.fix-getopt=   *.c
SUBST_SED.fix-getopt+=    -e 's,getopt_long_only,getopt_long,g'

.include "../../lang/perl5/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
