# $NetBSD: Makefile,v 1.7 2006/08/04 07:28:40 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=		4.3.90.2svn-22628

DISTNAME=		xfce4-panel-${XFCE4_VERSION}
PKGNAME=		xfce4-panel-${XFCE4_VERSION:S/svn-/./}
CATEGORIES=		x11
COMMENT=		Xfce panel

PKGCONFIG_OVERRIDE=	panel/xfce4-panel-1.0.pc.in
PTHREAD_AUTO_VARS=	yes

PKG_SYSCONFSUBDIR=	xdg/xfce4/panel
EGDIR=			${XFCE4_EGBASE}/panel
CONF_FILES=		${EGDIR:Q}/contents.xml ${PKG_SYSCONFDIR:Q}/contents.xml
.for l in ar az ca da el eu fi fr he hu it ja ko lt ms nl pl ro ru sk sv \
	tr vi zh_CN zh_TW
CONF_FILES+=		${EGDIR:Q}/contents.xml.${l} \
			${PKG_SYSCONFDIR:Q}/contents.xml.${l}
.endfor

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

REQD_DIRS+=		${XFCE4_EGBASE} ${EGDIR}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
