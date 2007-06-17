# $NetBSD: Makefile,v 1.1.1.1 2007/06/17 21:52:08 kheinz Exp $
#

PKGNAME=	pidgin-2.0.1

COMMENT=	Multi-protocol Instant Messaging client GTK frontend

PKG_DESTDIR_SUPPORT=	user-destdir

.include		"../../wip/libpurple/Makefile.common"  

USE_TOOLS+=		msgfmt

PKGCONFIG_OVERRIDE+=	gaim.pc.in
PKGCONFIG_OVERRIDE+=	libpurple/purple.pc.in
PKGCONFIG_OVERRIDE+=	pidgin/pidgin.pc.in

CONFIGURE_ARGS+=	--disable-gevolution
CONFIGURE_ARGS+=	--enable-gtkui
CONFIGURE_ARGS+=	--disable-consoleui

BUILD_DIRS=pidgin

.include "options.mk"

pre-build:
	# A hack to make it work. Should be done differently.
	${TEST} -r ${WRKSRC}/libpurple/libpurple.la || \
	  ${LN} -s ${BUILDLINK_DIR}/lib/libpurple.la ${WRKSRC}/libpurple/.

.include "../../wip/libpurple/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
