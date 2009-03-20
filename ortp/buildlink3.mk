# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	ortp

.if !defined(ORTP_BUILDLINK3_MK)
ORTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ortp+=	ortp>=0.13.1
BUILDLINK_PKGSRCDIR.ortp?=	../../wip/ortp
.endif # ORTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ortp
