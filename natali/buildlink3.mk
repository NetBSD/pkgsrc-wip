# $NetBSD: buildlink3.mk,v 1.5 2014/09/08 12:37:30 thomasklausner Exp $

BUILDLINK_TREE+=	natali

.if !defined(NATALI_BUILDLINK3_MK)
NATALI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.natali+=	natali>=1.25
BUILDLINK_ABI_DEPENDS.natali?=	natali>=1.25nb2
BUILDLINK_PKGSRCDIR.natali?=	../../wip/natali

.include "../../net/netatalk22/buildlink3.mk"
.endif # NATALI_BUILDLINK3_MK

BUILDLINK_TREE+=	-natali
