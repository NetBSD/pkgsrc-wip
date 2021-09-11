# $NetBSD$

DISTNAME=	libvirt-glib-2.0.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=libvirt/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libvirt.org/
COMMENT=	GLib-friendly libvirt wrapper
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake pkg-config gmake intltool

PKGCONFIG_OVERRIDE+=	libvirt-gconfig-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libvirt-glib-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libvirt-gobject-1.0.pc.in

CONFIGURE_SCRIPT=	autogen.sh

BUILDLINK_DEPMETHOD.vala:= build
.include "../../lang/vala/buildlink3.mk"
.include "../../wip/libvirt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
