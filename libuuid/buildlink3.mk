# $NetBSD: buildlink3.mk,v 1.6 2009/03/27 13:22:05 thomasklausner Exp $

BUILDLINK_TREE+=	libuuid

.if !defined(LIBUUID_BUILDLINK3_MK)
LIBUUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libuuid+=	libuuid>=1.36
BUILDLINK_PKGSRCDIR.libuuid?=	../../wip/libuuid

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # LIBUUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libuuid
