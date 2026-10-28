# $NetBSD$

DISTNAME=	jgmenu-4.7.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=jgmenu/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jgmenu.github.io/
COMMENT=	Freedesktop-compliant menu for openbox and tint2
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_TOOLS+=	gmake pkg-config

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec

CHECK_INTERPRETER_SKIP+=	libexec/jgmenu/*.py

.include "../../devel/glib2/schemas.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
