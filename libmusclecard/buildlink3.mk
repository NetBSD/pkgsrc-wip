# $NetBSD: buildlink3.mk,v 1.5 2009/05/06 10:09:30 cheusov Exp $

BUILDLINK_TREE+=	libmusclecard

.if !defined(LIBMUSCLECARD_BUILDLINK3_MK)
LIBMUSCLECARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmusclecard+=	libmusclecard>=1.2.9
BUILDLINK_PKGSRCDIR.libmusclecard?=	../../wip/libmusclecard

.include "../../security/pcsc-lite/buildlink3.mk"
.endif # LIBMUSCLECARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmusclecard
