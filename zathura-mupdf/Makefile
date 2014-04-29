# $NetBSD: Makefile,v 1.1 2014/04/29 22:42:45 leot1990 Exp $
#

VERSION=	0.2.6
PKGNAME=	zathura-mupdf-${VERSION}
DISTNAME=	zathura-pdf-mupdf-${VERSION}
CATEGORIES=	print
MASTER_SITES=	http://pwmt.org/projects/zathura/plugins/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura-pdf-mupdf/
COMMENT=	Add PDF support to zathura using mupdf rendering engine
#LICENSE=	# TODO: (see mk/license.mk)

CONFLICTS+=	zathura-poppler-[0-9]*

USE_TOOLS+=	pkg-config gettext gmake groff
USE_LIBTOOL=	yes

MAKE_ENV+=	MUPDF_LIB="-lmupdf -lmujs"

.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/mupdf/buildlink3.mk"
.include "../../wip/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
