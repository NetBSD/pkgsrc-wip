# $NetBSD$

BUILDLINK_TREE+=	graphviz

.if !defined(GRAPHVIZ_BUILDLINK3_MK)
GRAPHVIZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.graphviz+=	graphviz>=5.0.0
BUILDLINK_PKGSRCDIR.graphviz?=		../../wip/graphviz

DEPENDS+=	urw-fonts-[0-9]*:../../fonts/urw-fonts

# doxygen PLIST varies with pangocairo of PKG_OPTIONS
pkgbase := graphviz
.include "../../mk/pkg-build-options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # GRAPHVIZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-graphviz
