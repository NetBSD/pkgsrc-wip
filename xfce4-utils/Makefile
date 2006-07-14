# $NetBSD: Makefile,v 1.6 2006/07/14 10:52:26 thomasklausner Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=	xfce-utils-${XFCE4_VERSION}
PKGNAME=	xfce4-utils-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce utilities


PKG_SYSCONFSUBDIR=	xdg/xfce4
EGDIR=			${XFCE4_EGBASE}
CONF_FILES=		${EGDIR:Q}/xinitrc ${PKG_SYSCONFDIR:Q}/xinitrc

REQD_DIRS+=		${EGDIR}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
