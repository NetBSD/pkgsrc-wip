# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:11 noud4 Exp $
#

PKGNAME=		pidgin-evolution-${PIDGIN_VERSION}
COMMENT=		Evolution plugin for the Pidgin instant messenger

.include "../../chat/libpurple/Makefile.common"
MAINTAINER=		noud4@users.sourceforge.net

USE_TOOLS+=		msgfmt perl intltool

CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--enable-gtkui
CONFIGURE_ARGS+=	--disable-gtkspell
CONFIGURE_ARGS+=	--disable-screensaver
CONFIGURE_ARGS+=	--disable-sm
CONFIGURE_ARGS+=	--enable-gevolution

BUILD_DIRS=		pidgin/plugins/gevolution

.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
