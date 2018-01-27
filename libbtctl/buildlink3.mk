# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:04:24 cheusov Exp $

BUILDLINK_TREE+=	libbtctl

.if !defined(LIBBTCTL_BUILDLINK3_MK)
LIBBTCTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbtctl+=	libbtctl>=0.4.1
BUILDLINK_PKGSRCDIR.libbtctl?=		../../wip/libbtctl

.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../comms/openobex/buildlink3.mk"
.endif # LIBBTCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbtctl
