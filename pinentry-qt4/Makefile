# $NetBSD$

PKGNAME=		${DISTNAME:S/pinentry-/pinentry-qt4-/}
COMMENT=		Applications for entering PINs or Passphrases, qt4 enabled
CONFLICTS=		pinentry-qt5-[0-9]*

.include		"../../wip/pinentry/Makefile.common"

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config gmake

CONFIGURE_ARGS+=	--enable-pinentry-qt
CONFIGURE_ARGS+=	--disable-pinentry-curses
CONFIGURE_ARGS+=	--disable-pinentry-emacs
#CONFIGURE_ARGS+=	--disable-fallback-curses
CONFIGURE_ARGS+=	--disable-pinentry-gnome3
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-fltk
CONFIGURE_ARGS+=	--disable-pinentry-efl
CONFIGURE_ARGS+=	--disable-libsecret

INSTALL_DIRS=		qt

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../x11/qt4-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
