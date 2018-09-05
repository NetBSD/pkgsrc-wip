# $NetBSD$

BUILD_DIRS=	gb.xml/src/xslt
GB_DEPENDS=	gambas3-gb-xml
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-xml-xslt-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	XSLT tools for Gambas based on libxslt

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
