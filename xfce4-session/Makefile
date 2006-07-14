# $NetBSD: Makefile,v 1.1.1.1 2006/07/14 10:43:15 thomasklausner Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=		xfce4-session-${XFCE4_VERSION}
CATEGORIES=		x11
COMMENT=		Xfce session manager

PKG_SYSCONFSUBDIR=	xdg/xfce4-session
EGDIR=			${XFCE4_EGBASE}/session
CONF_FILES=		${EGDIR:Q}/xfce4-session.rc \
			${PKG_SYSCONFDIR:Q}/xfce4-session.rc

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q} \
			ICEAUTH=${TOOLS_PATH.iceauth:Q}

REQD_DIRS+=		${XFCE4_EGBASE} ${EGDIR}

USE_TOOLS+=		iceauth:run

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
