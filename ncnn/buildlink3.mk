# $NetBSD$

BUILDLINK_TREE+=	ncnn

.if !defined(NCNN_BUILDLINK3_MK)
NCNN_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.ncnn?=	build

BUILDLINK_API_DEPENDS.ncnn+=	ncnn>=20240820
BUILDLINK_PKGSRCDIR.ncnn?=	../../wip/ncnn

#.include "../../graphics/opencv/buildlink3.mk"
.endif	# NCNN_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncnn
