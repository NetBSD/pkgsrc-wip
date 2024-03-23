# $NetBSD$

BUILDLINK_TREE+=	fcft

.if !defined(FCFT_BUILDLINK3_MK)
FCFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fcft+=	fcft>=3.1.8
BUILDLINK_PKGSRCDIR.fcft?=	../../wip/fcft

.include "../../converters/utf8proc/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../wip/tllist/buildlink3.mk"
.endif	# FCFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcft
