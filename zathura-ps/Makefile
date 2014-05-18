# $NetBSD: Makefile,v 1.1 2014/05/18 11:46:24 leot1990 Exp $
#

VERSION=	0.2.2
DISTNAME=	zathura-ps-${VERSION}
CATEGORIES=	print
MASTER_SITES=	http://pwmt.org/projects/zathura-ps/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura-ps/
COMMENT=	Add PS support to zathura using libspectre library
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config gettext gmake groff
USE_LIBTOOL=	yes

.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../wip/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
