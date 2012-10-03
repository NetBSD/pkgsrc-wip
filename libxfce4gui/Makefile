# $NetBSD: Makefile,v 1.16 2012/10/03 09:10:41 asau Exp $

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
