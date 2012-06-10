# $NetBSD: Makefile,v 1.1.1.1 2012/06/10 12:38:33 leot1990 Exp $
#

DISTNAME=	sxiv-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/muennich/sxiv/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://github.com/muennich/sxiv
COMMENT=	Simple (or small or suckless) X Image Viewer
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing Makefile.
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e 's/gcc/${CC:Q}/'
SUBST_SED.makefile+=	-e 's,^CFLAGS *=,CFLAGS +=,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *=,LDFLAGS +=,'
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},'
SUBST_SED.makefile+=	-e '/install/s,-D,,'
SUBST_SED.makefile+=	-e '/install/s,bin/sxiv,bin,'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
