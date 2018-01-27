# $NetBSD: Makefile,v 1.13 2013/12/21 14:28:15 noud4 Exp $
#

DISTNAME=	grsync-1.2.0
CATEGORIES=	net
MASTER_SITES=	http://www.opbyte.it/release/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.opbyte.it/grsync/
COMMENT=	Grsync is a GUI for rsync
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config intltool msgfmt bash:run

REPLACE_BASH+=	src/grsync-batch

.include "../../devel/glade3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
