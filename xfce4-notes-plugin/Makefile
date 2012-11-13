# $NetBSD: Makefile,v 1.6 2012/11/13 20:09:36 othyro Exp $

.include "../../wip/xfce48/Makefile.common"

NOTES_VERSION=	1.7.7

DISTNAME=	xfce4-notes-plugin-${NOTES_VERSION}
PKGREVISION=	1
CATEGORIES=	sysutils
COMMENT=	Xfce notes plugin

MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-notes-plugin/1.7/


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
