# $NetBSD: Makefile,v 1.7 2012/10/07 20:11:10 asau Exp $
#

DISTNAME=	xtags-0.5
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xtags/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xtags.sourceforge.net/
COMMENT=	Little keyboard-driven Window Manager for X11
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing config.mk...
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,^CFLAGS =,CFLAGS +=,g'
SUBST_SED.makefile+=	-e 's,^LDFLAGS =,LDFLAGS +=,g'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
