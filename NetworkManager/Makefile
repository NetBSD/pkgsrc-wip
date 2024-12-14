# $NetBSD$

DISTNAME=	NetworkManager-1.50.0
CATEGORIES=	sysutils net
MASTER_SITES=	https://gitlab.freedesktop.org/NetworkManager/NetworkManager/-/archive/1.50.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://gitlab.freedesktop.org/NetworkManager/NetworkManager/-/archive/1.50.0/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=		pkg-config perl
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	src/libnm-client-impl/libnm.pc.in

CHECK_PORTABILITY_SKIP+=	contrib/scripts/checkpatch-git-post-commit-hook
CHECK_PORTABILITY_SKIP+=	contrib/scripts/code-style-git-post-commit-hook

MESON_ARGS+=	-Dsystemdsystemunitdir=no
MESON_ARGS+=	-Dsystemd_journal=false
MESON_ARGS+=	-Dsession_tracking=no
MESON_ARGS+=	-Dselinux=false
MESON_ARGS+=	-Dlibaudit=no
MESON_ARGS+=	-Dcrypto=null
MESON_ARGS+=	-Dppp=false
MESON_ARGS+=	-Dmodem_manager=false
MESON_ARGS+=	-Dovs=false
MESON_ARGS+=	-Dlibpsl=false
MESON_ARGS+=	-Dconcheck=false
MESON_ARGS+=	-Dnmcli=false
MESON_ARGS+=	-Dnmtui=false
MESON_ARGS+=	-Dnm_cloud_setup=false

.include "../../devel/meson/build.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../sysutils/libudev/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../wip/libndp/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
