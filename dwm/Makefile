# $NetBSD: Makefile,v 1.11 2009/02/08 16:52:48 leot1990 Exp $
#

DISTNAME=	dwm-5.4.1
CATEGORIES=	wm
MASTER_SITES=	http://code.suckless.org/dl/dwm/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://dwm.suckless.org/
COMMENT=	Dynamic window manager

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

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

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
