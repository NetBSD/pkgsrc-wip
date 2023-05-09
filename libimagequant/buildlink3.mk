# $NetBSD$

BUILDLINK_TREE+=	libimagequant

.if !defined(LIBIMAGEQUANT_BUILDLINK3_MK)
LIBIMAGEQUANT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libimagequant?=	build

BUILDLINK_API_DEPENDS.libimagequant+=	libimagequant>=4.2.0
BUILDLINK_PKGSRCDIR.libimagequant?=	../../wip/libimagequant
.endif	# LIBIMAGEQUANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libimagequant
