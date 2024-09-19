# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:01:55 cheusov Exp $

BUILDLINK_TREE+=	liblingoteach

.if !defined(LIBLINGOTEACH_BUILDLINK3_MK)
LIBLINGOTEACH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblingoteach+=	liblingoteach>=0.2.1
BUILDLINK_PKGSRCDIR.liblingoteach?=	../../wip/liblingoteach

.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBLINGOTEACH_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblingoteach
