# $NetBSD: Makefile,v 1.8 2010/06/13 22:47:06 thomasklausner Exp $
#

DISTNAME=	grsync-0.9.3
PKGREVISION=	1
CATEGORIES=	wip
MASTER_SITES=	http://www.opbyte.it/release/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.opbyte.it/grsync/
COMMENT=	Grsync is a GUI for rsync
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR= yes
USE_TOOLS+=	pkg-config intltool msgfmt bash:run

REPLACE_BASH+=	src/grsync-batch

.include "../../devel/glade3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

