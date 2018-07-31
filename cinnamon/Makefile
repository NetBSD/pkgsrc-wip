# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	cinnamon-3.8.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	Cinnamon
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/cinnamon
COMMENT=	Desktop Environment with layout similar to Gnome
LICENSE=	gnu-gpl-v2

NOT_PAX_MPROTECT_SAFE=	bin/cinnamon

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake bash pkg-config automake intltool
USE_LANGUAGES=	c c++

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ca-certificates=/etc/openssl/certs/ca-certificates.crt \
			--prefix=${PREFIX} \
			--mandir=${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	cinnamon-1.0.pc.in

SUBST_CLASSES=		prefix
SUBST_MESSAGE.prefix=	Fixing prefix references
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/st/st-background-effect.c
SUBST_FILES.prefix+=	src/st/st-texture-cache.c
SUBST_FILES.prefix+=	files/usr/bin/*
SUBST_FILES.prefix+=	files/usr/share/cinnamon/applets/*/*
SUBST_FILES.prefix+=	files/usr/share/cinnamon/cinnamon-desktop-editor/cinnamon-desktop-editor.py
SUBST_FILES.prefix+=	files/usr/share/cinnamon/cinnamon-menu-editor/cme/MainWindow.py
SUBST_FILES.prefix+=	files/usr/share/cinnamon/cinnamon-menu-editor/cme/config.py
SUBST_FILES.prefix+=	files/usr/share/cinnamon/cinnamon-screensaver-lock-dialog/cinnamon-screensaver-lock-dialog.py
SUBST_FILES.prefix+=	files/usr/share/cinnamon/cinnamon-settings-users/cinnamon-settings-users.py
SUBST_FILES.prefix+=	files/usr/share/cinnamon/cinnamon-settings/*/*.py
SUBST_FILES.prefix+=	files/usr/share/cinnamon/cinnamon-settings/*.py
SUBST_FILES.prefix+=	files/usr/share/cinnamon/desklets/launcher@cinnamon.org/editorDialog.py
SUBST_FILES.prefix+=	files/usr/share/cinnamon/desklets/launcher@cinnamon.org/desklet.js
SUBST_FILES.prefix+=	files/usr/share/cinnamon/thumbnails/gtk-3.0/README
SUBST_FILES.prefix+=	files/usr/share/cinnamon/thumbnails/metacity-1/README
SUBST_FILES.prefix+=	files/usr/share/dbus-1/services/org.Cinnamon.Melange.service
SUBST_FILES.prefix+=	files/usr/share/dbus-1/services/org.Cinnamon.Slideshow.service
SUBST_FILES.prefix+=	files/usr/share/polkit-1/actions/*
SUBST_FILES.prefix+=	files/usr/share/cinnamon/cinnamon-settings/bin/capi.py
SUBST_FILES.prefix+=	files/usr/share/cinnamon-session/sessions/*
SUBST_FILES.prefix+=	files/usr/share/xsessions/*.desktop
SUBST_FILES.prefix+=	js/ui/expo.js
SUBST_FILES.prefix+=	js/ui/main.js
SUBST_SED.prefix=	-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.prefix+=	-e 's,/usr/lib,${PREFIX}/lib,g'
SUBST_SED.prefix+=	-e 's,/etc/xdg,${PKG_SYSCONFDIR},g'
SUBST_SED.prefix+=	-e 's,/usr/bin,${PREFIX}/bin,g'
SUBST_SED.prefix+=	-e 's,nm-applet;,,g'

REPLACE_BASH=	files/usr/bin/cinnamon2d

REPLACE_PYTHON=	docs/reference/cinnamon-js/gen_doc.py \
		files/usr/bin/* \
		files/usr/share/cinnamon/*/*.py \
		files/usr/share/cinnamon/*/*/*.py

CONF_FILES+=	share/examples/menus/cinnamon-applications.menu \
		${PKG_SYSCONFDIR}/xdg/menus/cinnamon-applications.menu

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=1 ./autogen.sh && \
		${RM} -r ./files/usr/share/cinnamon/applets/network@cinnamon.org


INSTALLATION_DIRS+=	share/polkit-1/rules.d
post-install:
	${INSTALL_DATA} ${FILESDIR}/desktop.rules \
		${DESTDIR}${PREFIX}/share/polkit-1/rules.d/desktop.rules

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
.if ${OPSYS} != "SunOS"
DEPENDS+=	${PYPKGPREFIX}-pyinotify-[0-9]*:../../sysutils/py-pyinotify
.endif
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-pam-[0-9]*:../../wip/py-pam
DEPENDS+=	caribou-[0-9]*:../../x11/caribou
DEPENDS+=	keybinder3-[0-9]*:../../x11/keybinder3
DEPENDS+=	gst-plugins1-vpx-[0-9]*:../../multimedia/gst-plugins1-vpx
#DEPENDS+=	gnome-screenshot>=3.26:../../cinnamon/gnome-screenshot
DEPENDS+=	gnome-backgrounds>=3.26:../../graphics/gnome-backgrounds
DEPENDS+=	gnome-themes-standard>=3.20.0:../../graphics/gnome-themes-standard
DEPENDS+=	gnome-icon-theme-[0-9]*:../../graphics/gnome-icon-theme
#DEPENDS+=	gnome-terminal->=3.0.0:../../cinnamon/gnome-terminal
DEPENDS+=	mate-polkit-[0-9]*:../../security/mate-polkit
DEPENDS+=	mozilla-rootcerts-openssl-[0-9]*:../../security/mozilla-rootcerts-openssl

.include "../../lang/python/application.mk"
.include "../../devel/glib2/schemas.mk"

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../wip/cjs/buildlink3.mk"
.include "../../wip/cinnamon-menus/buildlink3.mk"
.include "../../wip/cinnamon-desktop/buildlink3.mk"
.include "../../wip/cinnamon-session/buildlink3.mk"
.include "../../wip/cinnamon-screensaver/buildlink3.mk"
.include "../../wip/cinnamon-control-center/buildlink3.mk"
.include "../../wip/cinnamon-settings-daemon/buildlink3.mk"
.include "../../wip/muffin/buildlink3.mk"
.include "../../wip/nemo/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
