# $NetBSD: buildlink3.mk,v 1.1 2015/03/27 00:22:55 outpaddling Exp $

BUILDLINK_TREE+=	auto-admin

.if !defined(AUTO_ADMIN_BUILDLINK3_MK)
AUTO_ADMIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.auto-admin+=	auto-admin>=0.3.5
BUILDLINK_PKGSRCDIR.auto-admin?=	../../wip/auto-admin
.endif	# AUTO_ADMIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-auto-admin
