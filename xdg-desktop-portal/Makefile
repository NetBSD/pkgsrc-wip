# $NetBSD$

DISTNAME=	xdg-desktop-portal-1.20.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=flatpak/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flatpak/xdg-desktop-portal/
COMMENT=	Desktop integration portal (from Flatpak)
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

# tests require umockdev
MESON_ARGS+=	-Dtests=disabled
# require bubblewrap
MESON_ARGS+=	-Dsandboxed-image-validation=disabled
MESON_ARGS+=	-Dsandboxed-sound-validation=disabled

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "NetBSD"
# shm_open
LDFLAGS+=	-lrt
.  if ${OPSYS_VERSION} >= 110000
# memfd_create(), seals
CFLAGS+=	-D_NETBSD_SOURCE
.  endif
.endif

post-install:
	${RM} -r ${DESTDIR}${PREFIX}/lib/systemd
	# fuse3 issue: see patch-document-portal_meson.build
	${RM} ${DESTDIR}${PREFIX}/share/dbus-1/interfaces/org.freedesktop.portal.Documents.xml
	${RM} ${DESTDIR}${PREFIX}/share/dbus-1/services/org.freedesktop.portal.Documents.service

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libportal/buildlink3.mk"
.include "../../geography/geoclue/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../wip/pipewire/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
