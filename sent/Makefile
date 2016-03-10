# $NetBSD$

DISTNAME=	sent-0.2
CATEGORIES=	wip
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dl.suckless.org/tools/
COMMENT=	Simple plaintext presentation tool
LICENSE=	mit

SUBST_CLASSES+=         makefile
SUBST_STAGE.makefile=   pre-configure
SUBST_MESSAGE.makefile= Adjust config.mk
SUBST_FILES.makefile=   config.mk
SUBST_SED.makefile+=    -e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=    -e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=    -e 's,/usr/X11R6,${X11BASE},'
SUBST_SED.makefile+=    -e '/^CPPFLAGS/ s,-DHAVE_SHADOW_H,,'
SUBST_SED.makefile+=    -e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=    -e 's,^CPPFLAGS *= ,CPPFLAGS += ,'
SUBST_SED.makefile+=    -e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.makefile+=    -e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=      bin ${PKGMANDIR}/man1

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../wip/farbfeld/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
