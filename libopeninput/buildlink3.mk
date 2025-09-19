# $NetBSD$

BUILDLINK_TREE+=	libopeninput

.if !defined(LIBOPENINPUT_BUILDLINK3_MK)
LIBOPENINPUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopeninput+=	libopeninput>=1.26.2
BUILDLINK_ABI_DEPENDS.libopeninput+=	libopeninput>=1.26.2
BUILDLINK_PKGSRCDIR.libopeninput?=	../../wip/libopeninput

.include "../../wip/input-headers/buildlink3.mk"

.endif # LIBOPENINPUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopeninput
