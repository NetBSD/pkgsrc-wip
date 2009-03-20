# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	liblingoteach

BUILDLINK_API_DEPENDS.liblingoteach+=	liblingoteach>=0.2.1
BUILDLINK_PKGSRCDIR.liblingoteach?=	../../wip/liblingoteach

.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBLINGOTEACH_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblingoteach
