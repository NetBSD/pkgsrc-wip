# $NetBSD: buildlink3.mk,v 1.2 2015/09/09 22:51:39 tnn2 Exp $

BUILDLINK_TREE+=	libdevq

.if !defined(LIBDEVQ_BUILDLINK3_MK)
LIBDEVQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdevq+=	libdevq>=0.0.2
BUILDLINK_PKGSRCDIR.libdevq?=	../../devel/libdevq
.endif # LIBDEVQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdevq
