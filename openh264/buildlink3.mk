# $NetBSD$

BUILDLINK_TREE+=	openh264

.if !defined(OPENH264_BUILDLINK3_MK)
OPENH264_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openh264+=	openh264>=1.5.0
BUILDLINK_PKGSRCDIR.openh264?=	../../wip/openh264

#.include "../../multimedia/gmp-api/buildlink3.mk"
.endif	# OPENH264_BUILDLINK3_MK

BUILDLINK_TREE+=	-openh264
