# $NetBSD: buildlink3.mk,v 1.5 2010/02/05 21:36:22 jakllsch Exp $

BUILDLINK_TREE+=	remctl

.if !defined(REMCTL_BUILDLINK3_MK)
REMCTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.remctl+=	remctl>=2.15
BUILDLINK_PKGSRCDIR.remctl?=	../../wip/remctl
.endif # REMCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-remctl
