# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	openal-soft

.if !defined(OPENAL_SOFT_BUILDLINK3_MK)
OPENAL_SOFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openal-soft+=	openal-soft>=1.2.218
#BUILDLINK_PKGSRCDIR.openal-soft?=	../../audio/openal-soft
BUILDLINK_PKGSRCDIR.openal-soft?=	../../wip/openal-soft

.include "../../mk/dlopen.buildlink3.mk"
.endif # OPENAL_SOFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-openal-soft
