# $NetBSD: Makefile,v 1.17 2013/06/17 12:45:12 thomasklausner Exp $

DISTNAME=	muffin-4.6.2
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	muffin
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/muffin
COMMENT=	Cinnamon window manager
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/muffin-4.6.2
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake automake intltool autoreconf
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	clutter/clutter/muffin-clutter.pc.in
PKGCONFIG_OVERRIDE+=	cogl/cogl-gles2/muffin-cogl-gles2.pc.in
PKGCONFIG_OVERRIDE+=	cogl/cogl-pango/muffin-cogl-pango.pc.in
PKGCONFIG_OVERRIDE+=	cogl/cogl-path/muffin-cogl-path.pc.in
PKGCONFIG_OVERRIDE+=	cogl/cogl/muffin-cogl.pc.in
PKGCONFIG_OVERRIDE+=	src/libmuffin.pc.in
PKGCONFIG_OVERRIDE+=	src/muffin-plugins.pc.in

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=1 ./autogen.sh

.include "../../audio/libcanberra/buildlink3.mk"
#.include "../../graphics/clutter/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../wip/cinnamon-desktop/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
