# $NetBSD: buildlink3.mk,v 1.1 2015/09/05 02:34:31 dshao Exp $

BUILDLINK_TREE+=	libdevq

.if !defined(LIBDEVQ_BUILDLINK3_MK)
LIBDEVQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdevq+=	libdevq>=0.0.2
BUILDLINK_PKGSRCDIR.libdevq?=	../../devel/libdevq
.include "../../mk/dlopen.buildlink3.mk"
.endif # LIBDEVQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdevq
