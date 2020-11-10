# $NetBSD$

DISTNAME=	gnome-shell-3.38.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-shell/3.38/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://wiki.gnome.org/Projects/GnomeShell
COMMENT=	Next generation GNOME shell
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes

USE_TOOLS+=	pkg-config perl

MESON_ARGS+=	-Dnetworkmanager=false
MESON_ARGS+=	-Dsystemd=false
MESON_ARGS+=	-Dextensions_app=false
MESON_ARGS+=	-Dextensions_tool=false

TOOL_DEPENDS+=	sassc>=3.6:../../www/sassc
TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	gdbus-codegen>=2.64:../../devel/gdbus-codegen

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/subprojects/gvc

REPLACE_PYTHON+=	meson/*.py

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/gnome-shell

post-extract:
	cp ${FILESDIR}/*.xml ${WRKSRC}/data/dbus-interfaces/

.include "../../devel/meson/build.mk"
.include "../../archivers/gnome-autoar/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/at-spi2-atk/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../wip/gjs/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../wip/mutter/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
