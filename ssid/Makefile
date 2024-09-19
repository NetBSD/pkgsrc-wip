# $NetBSD: Makefile,v 1.2 2012/10/07 16:23:16 asau Exp $
#

DISTNAME=	ssid-0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://tools.suckless.org/ssid/
COMMENT=	Simple setsid replacement
LICENSE=	mit

NO_CONFIGURE=	yes

# Adjust config.mk
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,^CFLAGS = ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS = ,LDFLAGS += ,'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

.include "../../mk/bsd.pkg.mk"
