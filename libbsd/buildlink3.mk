# $NetBSD: buildlink3.mk,v 1.2 2013/01/03 21:41:42 mrampke Exp $

BUILDLINK_TREE+=	libbsd

.if !defined(LIBBSD_BUILDLINK3_MK)
LIBBSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbsd+=	libbsd>=0.10.0
BUILDLINK_PKGSRCDIR.libbsd?=	../../wip/libbsd
.endif	# LIBBSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbsd
