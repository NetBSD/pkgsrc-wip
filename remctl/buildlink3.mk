# $NetBSD: buildlink3.mk,v 1.4 2009/05/23 15:49:21 jakllsch Exp $

BUILDLINK_TREE+=	remctl

.if !defined(REMCTL_BUILDLINK3_MK)
REMCTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.remctl+=	remctl>=2.14
BUILDLINK_PKGSRCDIR.remctl?=	../../wip/remctl
.endif # REMCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-remctl
