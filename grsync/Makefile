# $NetBSD: Makefile,v 1.3 2009/03/24 12:49:25 jihbed Exp $
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

NO_CHECKSUM=	yes

REPLACE_BASH+=	src/grsync-batch

.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
