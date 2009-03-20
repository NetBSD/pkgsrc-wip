# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:52 jsonn Exp $

BUILDLINK_TREE+=	remctl

.if !defined(REMCTL_BUILDLINK3_MK)
REMCTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.remctl+=	remctl>=2.13
BUILDLINK_PKGSRCDIR.remctl?=	../../wip/remctl
.endif # REMCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-remctl
