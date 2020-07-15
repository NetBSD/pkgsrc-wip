# $NetBSD$

DISTNAME=	granite-5.5.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=elementary/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/elementary/granite/
COMMENT=	Elementary OS Gtk+/GLib extension library
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_TOOLS=		pkg-config
USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../devel/meson/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
