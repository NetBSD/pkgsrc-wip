# $NetBSD$

DISTNAME=	vala-panel-appmenu-0.7.3.2
CATEGORIES=	x11
MASTER_SITES=	https://gitlab.com/vala-panel-project/vala-panel-appmenu/-/archive/0.7.3.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/vala-panel-project/vala-panel-appmenu/-/archive/0.7.3.2/
COMMENT=	Global Menu for Vala Panel (and xfce4-panel and mate-panel)
LICENSE=	gnu-lgpl-v3

USE_CMAKE=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	subprojects/appmenu-gtk-module/data/appmenu-gtk2-parser.pc.in
PKGCONFIG_OVERRIDE+=	subprojects/appmenu-gtk-module/data/appmenu-gtk3-parser.pc.in

.include "../../devel/meson/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../wip/bamf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
