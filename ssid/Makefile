# $NetBSD: Makefile,v 1.1.1.1 2011/01/03 13:16:17 rubengonzalez Exp $
#

DISTNAME=	ssid-0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://tools.suckless.org/ssid/
COMMENT=	Simple setsid replacement
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=   yes

# Adjust config.mk
SUBST_CLASSES+=         makefile
SUBST_STAGE.makefile=   pre-build
SUBST_MESSAGE.makefile= Fixing config.mk
SUBST_FILES.makefile=   config.mk
SUBST_SED.makefile+=    -e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=    -e 's,^CFLAGS = ,CFLAGS += ,'
SUBST_SED.makefile+=    -e 's,^LDFLAGS = ,LDFLAGS += ,'
SUBST_SED.makefile+=    -e 's/cc/${CC:Q}/'

.include "../../mk/bsd.pkg.mk"
