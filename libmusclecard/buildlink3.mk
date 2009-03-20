# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	libmusclecard

BUILDLINK_API_DEPENDS.libmusclecard+=	libmusclecard>=1.2.9
BUILDLINK_PKGSRCDIR.libmusclecard?=	../../wip/libmusclecard

.include "../../security/pcsc-lite/buildlink3.mk"
.endif # LIBMUSCLECARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmusclecard
