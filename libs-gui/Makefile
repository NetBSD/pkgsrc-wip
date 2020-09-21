# $NetBSD$

GITHUB_PROJECT=	libs-gui
GITHUB_TAG=	gui-0_28_0
DISTNAME=	gui-0_28_0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/gui-//:S/_/./g}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnustep/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gnustep/libs-gui/
COMMENT=	Replacement of x11/gnustep-gui
LICENSE=	gnu-lgpl-v2.1 OR gnu-gpl-v3

WRKSRC=			${WRKDIR}/libs-gui-gui-0_28_0
USE_TOOLS+=		gmake
USE_LANGUAGES=		objc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
MAKE_FILE=		GNUmakefile

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
