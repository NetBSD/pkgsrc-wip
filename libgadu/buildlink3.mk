# $NetBSD: buildlink3.mk,v 1.5 2010/03/14 23:03:55 shindenmorr Exp $

BUILDLINK_TREE+=	libgadu

.if !defined(LIBGADU_BUILDLINK3_MK)
LIBGADU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgadu+=	libgadu>=1.9.0
BUILDLINK_ABI_DEPENDS.libgadu+=	libgadu>=1.9.0
BUILDLINK_PKGSRCDIR.libgadu?=	../../wip/libgadu
.endif # LIBGADU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgadu
