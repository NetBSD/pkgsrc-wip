# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/09/02 12:26:06 jihbed Exp $

BUILDLINK_TREE+=	libscscp

.if !defined(LIBSCSCP_BUILDLINK3_MK)
LIBSCSCP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libscscp+=	libscscp>=0.6.1
BUILDLINK_PKGSRCDIR.libscscp?=		../../wip/libscscp

.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBSCSCP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libscscp
