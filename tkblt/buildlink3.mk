# $NetBSD$

BUILDLINK_TREE+=	tkblt

.if !defined(TKBLT_BUILDLINK3_MK)
TKBLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tkblt+=	tkblt>=3.2.23
BUILDLINK_PKGSRCDIR.tkblt?=	../../wip/tkblt

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif	# TKBLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tkblt
