# $NetBSD: buildlink3.mk,v 1.1 2011/10/29 01:11:26 othyro Exp $

BUILDLINK_TREE+=	ucommon

.if !defined(UCOMMON_BUILDLINK3_MK)
UCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ucommon+=	ucommon>=5.0.6
BUILDLINK_PKGSRCDIR.ucommon?=	../../wip/ucommon

.endif # UCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-ucommon
