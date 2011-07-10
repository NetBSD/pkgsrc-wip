# $NetBSD: Makefile,v 1.4 2011/07/10 18:58:01 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

NOTES_VERSION=	1.7.7

DISTNAME=	xfce4-notes-plugin-${NOTES_VERSION}
#PKGREVISION=	1
CATEGORIES=	sysutils
COMMENT=	Xfce notes plugin

MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-notes-plugin/1.7/

.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
