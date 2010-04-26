# $NetBSD: buildlink3.mk,v 1.5 2010/04/26 15:38:29 shindenmorr Exp $

BUILDLINK_TREE+=	libdshconfig

.if !defined(LIBDSHCONFIG_BUILDLINK3_MK)
LIBDSHCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdshconfig+=	libdshconfig>=0.20.13
BUILDLINK_PKGSRCDIR.libdshconfig?=	../../wip/libdshconfig
.endif	# LIBDSHCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdshconfig
