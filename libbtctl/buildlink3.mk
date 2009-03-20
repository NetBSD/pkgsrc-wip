# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	libbtctl

BUILDLINK_API_DEPENDS.libbtctl+=	libbtctl>=0.4.1
BUILDLINK_PKGSRCDIR.libbtctl?=	../../wip/libbtctl

.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../comms/openobex/buildlink3.mk"
.endif # LIBBTCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbtctl
