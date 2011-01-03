# $NetBSD: Makefile,v 1.1.1.1 2011/01/03 00:47:19 rubengonzalez Exp $
#

DISTNAME=	swarp-0.1
PKGREVISION= 	1
CATEGORIES=     x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://tools.suckless.org/swarp
COMMENT=	Simple mouse pointer warping tool for X
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=   yes

# Adjust config.mk
SUBST_CLASSES+=         makefile
SUBST_STAGE.makefile=   pre-build
SUBST_MESSAGE.makefile= Fixing config.mk
SUBST_FILES.makefile=   config.mk
SUBST_SED.makefile+=    -e 's,/usr/local,${PREFIX},g'
# no manual avaiable
#SUBST_SED.makefile+=   -e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=    -e 's,/usr/X11R6,${X11BASE},g'
SUBST_SED.makefile+=    -e 's,^CFLAGS = ,CFLAGS += ,'
SUBST_SED.makefile+=    -e 's,^LDFLAGS = ,LDFLAGS += ,'
SUBST_SED.makefile+=    -e 's/cc/${CC:Q}/'

# no manual avaiable
#INSTALLATION_DIRS=      bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
