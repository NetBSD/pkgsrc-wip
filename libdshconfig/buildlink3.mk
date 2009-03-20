# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	libdshconfig

.if !defined(LIBDSHCONFIG_BUILDLINK3_MK)
LIBDSHCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdshconfig+=	libdshconfig>=0.20.9
BUILDLINK_DEPMETHOD.libdshconfig?=	build
BUILDLINK_PKGSRCDIR.libdshconfig?=	../../wip/libdshconfig
.endif # LIBDSHCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdshconfig
