# $NetBSD: Makefile,v 1.5 2009/05/19 09:00:14 thomasklausner Exp $
#

DISTNAME=	xtags-0.5
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xtags/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://xtags.sourceforge.net/
COMMENT=	Little keyboard-driven Window Manager for X11
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing config.mk...
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=    -e 's,^CFLAGS =,CFLAGS +=,g'
SUBST_SED.makefile+=    -e 's,^LDFLAGS =,LDFLAGS +=,g'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
