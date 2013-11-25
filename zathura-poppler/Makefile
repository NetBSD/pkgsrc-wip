# $NetBSD: Makefile,v 1.4 2013/11/25 19:19:14 zul_ Exp $
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

USE_TOOLS+=	pkg-config gettext gmake groff
USE_LIBTOOL=	yes

.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../wip/zathura/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
