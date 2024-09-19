# $NetBSD$

DISTNAME=	svkbd-fc267005ced2251de9e05e62e8a2b42a2712236a
PKGNAME=	svkbd-0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://git.suckless.org/svkbd/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tools.suckless.org/x/svkbd
COMMENT=	Simple virtual keyboard
LICENSE=	mit

USE_TOOLS+=	gmake

# Adjust config.mk
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,/usr/X11R6,${X11BASE},'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

#BUILD_TARGET=	svdkbd-en
#BUILD_TARGET+=	svdkbd-de
#BUILD_TARGET+=	svdkbd-ru
#BUILD_TARGET+=	svdkbd-sh

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
