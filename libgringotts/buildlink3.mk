# $NetBSD$

BUILDLINK_TREE+=	libgringotts

.if !defined(LIBGRINGOTTS_BUILDLINK3_MK)
LIBGRINGOTTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgringotts+=	libgringotts>=1.2.1
BUILDLINK_PKGSRCDIR.libgringotts?=	../../wip/libgringotts

.include "../../security/libmcrypt/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.endif	# LIBGRINGOTTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgringotts
