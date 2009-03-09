# $NetBSD: Makefile,v 1.2 2009/03/09 23:25:18 jihbed Exp $
#

DISTNAME=	grsync-0.6.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.opbyte.it/release/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.opbyte.it/grsync/
COMMENT=	Grsync is a GUI for rsync

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool msgfmt pkg-config bash:run
USE_DIRS+=	xdg-1.4

REPLACE_BASH+=	src/grsync-batch

.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
