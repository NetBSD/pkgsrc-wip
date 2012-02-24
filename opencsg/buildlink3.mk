# $NetBSD: buildlink3.mk,v 1.1 2012/02/24 21:17:45 reinoudz70 Exp $

BUILDLINK_TREE+=	opencsg

.if !defined(OPENCSG_BUILDLINK3_MK)
OPENCSG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencsg+=	opencsg>=1.3.2
BUILDLINK_ABI_DEPENDS.opencsg?=	opencsg>=1.3.2
BUILDLINK_PKGSRCDIR.opencsg?=	../../wip/opencsg

.endif # OPENCSG_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencsg
