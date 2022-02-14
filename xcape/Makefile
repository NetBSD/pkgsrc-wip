# $NetBSD$

DISTNAME=	xcape-1.2
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=alols/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pickles@tilde.pink
HOMEPAGE=	https://github.com/alols/xcape/
COMMENT=	Configure modifier keys to act as other keys when pressed
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's,/usr,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,local/man,${PKGMANDIR},g'

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
