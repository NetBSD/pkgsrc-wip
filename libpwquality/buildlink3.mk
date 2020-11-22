# $NetBSD$

BUILDLINK_TREE+=	libpwquality

.if !defined(LIBPWQUALITY_BUILDLINK3_MK)
LIBPWQUALITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpwquality+=	libpwquality>=1.3.0
BUILDLINK_PKGSRCDIR.libpwquality?=	../../wip/libpwquality

.include "../../security/cracklib/buildlink3.mk"
.endif	# LIBPWQUALITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpwquality
