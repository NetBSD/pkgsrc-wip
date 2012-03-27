# $NetBSD: buildlink3.mk,v 1.2 2012/03/27 17:11:23 outpaddling Exp $

BUILDLINK_TREE+=	ufc

.if !defined(UFC_BUILDLINK3_MK)
UFC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ufc+=	ufc>=2.0.5
BUILDLINK_PKGSRCDIR.ufc?=	../../wip/ufc
.endif	# UFC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ufc
