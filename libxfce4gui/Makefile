# $NetBSD: Makefile,v 1.12 2007/04/11 14:12:57 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=	libxfcegui4-${XFCE4_VERSION}
PKGNAME=	libxfce4gui-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce widget library

USE_TOOLS+=		msgfmt
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX:Q}/share/doc

PKGCONFIG_OVERRIDE=	libxfcegui4/libxfcegui4-1.0.pc.in

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
