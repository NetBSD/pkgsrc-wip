# $NetBSD$

PKGNAME=	${DISTNAME:S/pinentry-/pinentry-fltk-/}
PKGREVISION=	2
COMMENT=	Applications for entering PINs or Passphrases, FLTK enabled

.include "../../security/pinentry/Makefile.common"

PATCHDIR=	${.CURDIR}/../../wip/pinentry-fltk/patches

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--disable-libsecret
CONFIGURE_ARGS+=	--disable-pinentry-curses
CONFIGURE_ARGS+=	--disable-pinentry-efl
CONFIGURE_ARGS+=	--disable-pinentry-emacs
CONFIGURE_ARGS+=	--disable-pinentry-gnome3
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-qt
CONFIGURE_ARGS+=	--disable-pinentry-qt5
CONFIGURE_ARGS+=	--enable-pinentry-fltk

INSTALL_DIRS=		fltk

USE_TOOLS+=	aztoconf automake autoreconf

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -fi

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
