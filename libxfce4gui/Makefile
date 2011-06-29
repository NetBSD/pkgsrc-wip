# $NetBSD: Makefile,v 1.15 2011/06/29 10:45:24 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

XFCE4_VERSION=	4.8.1
PKGNAME=	libxfce4gui-${XFCE4_VERSION}
DISTNAME=	libxfcegui4-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce widget library

XFCE4_PROJECT=  libxfcegui4
XFCE4_BRANCH=   4.8

PKGCONFIG_OVERRIDE=	libxfcegui4/libxfcegui4-1.0.pc.in

CONFIGURE_ARGS+=	--disable-gladeui

#MAKE_DIRS+=	${PKG_SYSCONFDIR} ${PREFIX}/include/xfce4
#MAKE_DIRS+=	${XFCE4_EGBASE} ${XFCE4_EGBASE:Q}/xfconf ${EGDIR}
#OWN_DIRS+=	${PKG_SYSCONFDIR}/xfce4 ${PKG_SYSCONFDIR}/xfce4/xfconf
#OWN_DIRS+=	${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml

.include "../../devel/libglade/buildlink3.mk"
#.include "../../devel/xfconf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
