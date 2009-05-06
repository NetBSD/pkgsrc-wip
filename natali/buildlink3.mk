# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:13:22 cheusov Exp $

BUILDLINK_TREE+=	natali

.if !defined(NATALI_BUILDLINK3_MK)
NATALI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.natali+=	natali>=1.25
BUILDLINK_PKGSRCDIR.natali?=	../../wip/natali

.include "../../net/netatalk/buildlink3.mk"
.endif # NATALI_BUILDLINK3_MK

BUILDLINK_TREE+=	-natali
