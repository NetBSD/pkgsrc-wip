# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/03 21:33:00 zecrazytux Exp $

BUILDLINK_TREE+=	xerces-c

.if !defined(XERCES_C_BUILDLINK3_MK)
XERCES_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xerces-c+=	xerces-c>=3.1.1
BUILDLINK_ABI_DEPENDS.xerces-c?=	xerces-c>=3.1.1
BUILDLINK_PKGSRCDIR.xerces-c?=	../../wip/xerces-c

.endif # XERCES_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xerces-c
