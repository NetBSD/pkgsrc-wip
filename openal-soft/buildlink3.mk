# $NetBSD: buildlink3.mk,v 1.3 2009/09/01 12:33:10 thomasklausner Exp $

BUILDLINK_TREE+=	openal-soft

.if !defined(OPENAL_SOFT_BUILDLINK3_MK)
OPENAL_SOFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openal-soft+=	openal-soft>=1.5.304
BUILDLINK_PKGSRCDIR.openal-soft?=	../../wip/openal-soft
.endif	# OPENAL_SOFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-openal-soft
