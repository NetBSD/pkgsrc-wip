# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/09/02 12:35:38 jihbed Exp $

BUILDLINK_TREE+=	jason

.if !defined(JASON_BUILDLINK3_MK)
JASON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jason+=	jason>=1.3.3
BUILDLINK_PKGSRCDIR.jason?=	../../wip/jason
.endif	# JASON_BUILDLINK3_MK

BUILDLINK_TREE+=	-jason
