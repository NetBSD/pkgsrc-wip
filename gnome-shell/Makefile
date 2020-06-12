# $NetBSD$

DISTNAME=	gnome-shell-3.36.3
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-shell/3.36/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://wiki.gnome.org/Projects/GnomeShell
COMMENT=	Next generation GNOME shell
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes

USE_TOOLS+=	pkg-config perl
USE_LIBTOOL=	yes
USE_LANGUAGES=	c

MESON_ARGS+=	-Dnetworkmanager=false
MESON_ARGS+=	-Dsystemd=false

TOOL_DEPENDS+=	sassc>=3.6:../../www/sassc
TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	gdbus-codegen>=2.64:../../devel/gdbus-codegen

MAKE_ENV+=      LD_LIBRARY_PATH=${WRKSRC}/output/subprojects/gvc

.include "../../textproc/json-glib/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../wip/gnome-autoar/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../wip/gnome-desktop3/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../wip/mutter/buildlink3.mk"
.include "../../wip/gjs/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../devel/at-spi2-atk/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
