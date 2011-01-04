# $NetBSD: Makefile,v 1.1.1.1 2011/01/04 15:48:52 rubengonzalez Exp $
#

DISTNAME=	lsw-0.1
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://tools.suckless.org/lsw/
COMMENT=	Lists the titles of all running X windows to stdout
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=   yes

# Adjust config.mk
SUBST_CLASSES+=         makefile
SUBST_STAGE.makefile=   pre-build
SUBST_MESSAGE.makefile= Fixing config.mk
SUBST_FILES.makefile=   config.mk
SUBST_SED.makefile+=    -e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=    -e 's,/usr/X11R6,${X11BASE},g'
SUBST_SED.makefile+=    -e 's,^CFLAGS = ,CFLAGS += ,'
SUBST_SED.makefile+=    -e 's,^LDFLAGS = ,LDFLAGS += ,'
SUBST_SED.makefile+=    -e 's/cc/${CC:Q}/'

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
