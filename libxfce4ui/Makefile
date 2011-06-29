# $NetBSD: Makefile,v 1.2 2011/06/29 19:48:58 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	libxfce4ui-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce widget library

XFCE4_PROJECT=  libxfce4ui
XFCE4_BRANCH=   4.8

PKGCONFIG_OVERRIDE=	libxfce4kbd-private/libxfce4kbd-private-2.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4ui/libxfce4ui-1.pc.in

CONFIGURE_ARGS+=	--disable-gladeui

EGDIR=			${XFCE4_EGBASE}/xfconf/xfce-perchannel-xml
PKG_SYSCONFSUBDIR=	xdg
CONF_FILES=		${EGDIR}/xfce4-keyboard-shortcuts.xml \
	${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml/xfce4-keyboard-shortcuts.xml

#MAKE_DIRS+=	${PKG_SYSCONFDIR} ${PREFIX}/include/xfce4
#MAKE_DIRS+=	${XFCE4_EGBASE} ${XFCE4_EGBASE:Q}/xfconf ${EGDIR}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml/
#OWN_DIRS+=	${PKG_SYSCONFDIR}/xfce4 ${PKG_SYSCONFDIR}/xfce4/xfconf
#OWN_DIRS+=	${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml

#.include "../../devel/libglade/buildlink3.mk"
.include "../../wip/xfconf/buildlink3.mk"
#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
