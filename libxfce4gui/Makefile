# $NetBSD: Makefile,v 1.7 2006/08/04 07:28:40 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	4.3.90.2svn-22628

DISTNAME=	libxfcegui4-${XFCE4_VERSION}
PKGNAME=	libxfce4gui-${XFCE4_VERSION:S/svn-/./}
CATEGORIES=	x11
COMMENT=	Xfce widget library

USE_TOOLS+=	msgfmt
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX:Q}/share/doc/html

PKGCONFIG_OVERRIDE=	libxfcegui4/libxfcegui4-1.0.pc.in

.include "../../databases/dbh/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
