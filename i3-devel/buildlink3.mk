# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/12/07 21:21:16 pallegra Exp $

BUILDLINK_TREE+=	i3

.if !defined(I3_BUILDLINK3_MK)
I3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.i3+=	i3>=4devel1
BUILDLINK_PKGSRCDIR.i3?=	../../wip/i3-devel

.endif	# I3_BUILDLINK3_MK

BUILDLINK_TREE+=	-i3
