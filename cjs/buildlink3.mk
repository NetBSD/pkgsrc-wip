# $NetBSD$

BUILDLINK_TREE+=	cjs

.if !defined(CJS_BUILDLINK3_MK)
CJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cjs+=	cjs>=3.8.0
BUILDLINK_PKGSRCDIR.cjs?=	../../wip/cjs

.include "../../lang/spidermonkey185/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# CJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cjs
