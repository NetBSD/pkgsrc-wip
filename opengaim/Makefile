# $NetBSD: Makefile,v 1.5 2004/08/17 18:31:36 tvierling Exp $
#

DISTNAME=	opengaim-0.76a
CATEGORIES=	chat x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opengaim/}

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://opengaim.sourceforge.net/
COMMENT=	GTK2 based multiprotocol instant messaging client

BUILD_USES_MSGFMT=	YES

CONFLICTS+=	gaim-gnome-[0-9]* gaim-[0-9]*

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
LIBTOOL_LA_FILES+=	lib/gaim/autorecon.la
LIBTOOL_LA_FILES+=	lib/gaim/docklet.la
LIBTOOL_LA_FILES+=	lib/gaim/gaim-remote.la
LIBTOOL_LA_FILES+=	lib/gaim/gestures.la
LIBTOOL_LA_FILES+=	lib/gaim/history.la
LIBTOOL_LA_FILES+=	lib/gaim/iconaway.la
LIBTOOL_LA_FILES+=	lib/gaim/idle.la
LIBTOOL_LA_FILES+=	lib/gaim/libgg.la
LIBTOOL_LA_FILES+=	lib/gaim/libirc.la
LIBTOOL_LA_FILES+=	lib/gaim/libjabber.la
LIBTOOL_LA_FILES+=	lib/gaim/libmsn.la
LIBTOOL_LA_FILES+=	lib/gaim/libnapster.la
LIBTOOL_LA_FILES+=	lib/gaim/liboscar.la
LIBTOOL_LA_FILES+=	lib/gaim/libtoc.la
LIBTOOL_LA_FILES+=	lib/gaim/libyahoo.la
LIBTOOL_LA_FILES+=	lib/gaim/libzephyr.la
LIBTOOL_LA_FILES+=	lib/gaim/notify.la
LIBTOOL_LA_FILES+=	lib/gaim/spellchk.la
LIBTOOL_LA_FILES+=	lib/gaim/ssl-gnutls.la
LIBTOOL_LA_FILES+=	lib/gaim/ssl-nss.la
LIBTOOL_LA_FILES+=	lib/gaim/ssl.la
LIBTOOL_LA_FILES+=	lib/gaim/statenotify.la
LIBTOOL_LA_FILES+=	lib/gaim/ticker.la
LIBTOOL_LA_FILES+=	lib/gaim/timestamp.la
LIBTOOL_LA_FILES+=	lib/libgaim-remote.la
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

CONFIGURE_ARGS+=	--disable-nas
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-nss
CONFIGURE_ARGS+=	--disable-tcl

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/extensions/scrnsaver.h)
CONFIGURE_ARGS+=	--disable-screensaver
.endif

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.if !defined(OPENGAIM_USE_GTKSPELL) || empty(OPENGAIM_USE_GTKSPELL:M[Nn][Oo])
.include "../../textproc/gtkspell/buildlink3.mk"
.endif
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
