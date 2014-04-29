# $NetBSD: Makefile,v 1.5 2014/04/29 22:46:54 leot1990 Exp $
#

VERSION=	0.2.4
PKGNAME=	zathura-poppler-${VERSION}
DISTNAME=	zathura-pdf-poppler-${VERSION}
CATEGORIES=	print
MASTER_SITES=	http://pwmt.org/projects/zathura/plugins/download/

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura/
COMMENT=	Add PDF support to zathura using poppler rendering engine
#LICENSE=	# TODO: (see mk/license.mk)

CONFLICTS+=	zathura-mupdf-[0-9]*

USE_TOOLS+=	pkg-config gettext gmake groff
USE_LIBTOOL=	yes

.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../wip/zathura/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
