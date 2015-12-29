# $NetBSD: Makefile,v 1.2 2015/09/03 22:35:17 leot1990 Exp $
#

VERSION=	0.2.5
DISTNAME=	zathura-djvu-${VERSION}
CATEGORIES=	print
MASTER_SITES=	http://pwmt.org/projects/zathura-djvu/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura-djvu/
COMMENT=	Add DjVu support to zathura using djvulibre library
LICENSE=	zlib

USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/zathura/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
