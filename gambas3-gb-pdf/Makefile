# $NetBSD$

BUILD_DIRS=	gb.pdf
GB_DEPENDS=	gambas3-gb-image
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-pdf-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	PDF renderer for Gambas based on Poppler

.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
