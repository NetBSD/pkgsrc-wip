# $NetBSD: Makefile,v 1.1.1.1 2011/03/07 19:08:11 amoibos Exp $

DISTNAME=	tabbed-0.3
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://dl.suckless.org/tools/
COMMENT=	Simple generic tabbed frontend to xembed aware applications
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

NO_CONFIGURE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

# Adjust config.mk
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,/usr/X11R6,${X11BASE},'
SUBST_SED.makefile+=	-e 's,^CFLAGS = ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS = ,LDFLAGS += ,'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
