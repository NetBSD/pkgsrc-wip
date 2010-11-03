# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/03 21:41:24 zecrazytux Exp $

BUILDLINK_TREE+=	xqilla

.if !defined(XQILLA_BUILDLINK3_MK)
XQILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xqilla+=	xqilla>=2.2.4
BUILDLINK_PKGSRCDIR.xqilla?=	../../wip/xqilla
.endif	# XQILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-xqilla
