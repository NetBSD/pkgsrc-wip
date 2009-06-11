# $NetBSD: Makefile,v 1.5 2009/06/11 18:19:32 jihbed Exp $
#

DISTNAME=	grsync-0.9.0
CATEGORIES=	sysutils
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
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

