# $NetBSD$

BUILDLINK_TREE+=	alure

.if !defined(ALURE_BUILDLINK3_MK)
ALURE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alure+=	alure>=1.2
BUILDLINK_PKGSRCDIR.alure?=	../../audio/alure

.include "../../audio/openal-soft/buildlink3.mk"
.endif	# ALURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-alure
