# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/13 13:18:23 helgoman Exp $

BUILDLINK_TREE+=	cx_Freeze

.if !defined(CX_FREEZE_BUILDLINK3_MK)
CX_FREEZE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cx_Freeze+=	cx_Freeze>=4.1.2nb1
BUILDLINK_PKGSRCDIR.cx_Freeze?=	../../wip/cxfreeze
.endif	# CX_FREEZE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cx_Freeze
