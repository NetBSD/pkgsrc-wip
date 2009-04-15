# $NetBSD: Makefile,v 1.4 2009/04/15 10:48:42 jihbed Exp $
#

DISTNAME=	grsync-0.6.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.opbyte.it/release/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.opbyte.it/grsync/
COMMENT=	Grsync is a GUI for rsync

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool msgfmt bash:run
USE_DIRS+=	xdg-1.4


REPLACE_BASH+=	src/grsync-batch

.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
