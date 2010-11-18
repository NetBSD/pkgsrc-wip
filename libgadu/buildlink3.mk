# $NetBSD: buildlink3.mk,v 1.6 2010/11/18 14:57:06 shindenmorr Exp $

BUILDLINK_TREE+=	libgadu

.if !defined(LIBGADU_BUILDLINK3_MK)
LIBGADU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgadu+=	libgadu>=1.9.0rc2
BUILDLINK_ABI_DEPENDS.libgadu+=	libgadu>=1.9.0rc2
BUILDLINK_PKGSRCDIR.libgadu?=	../../wip/libgadu
.endif # LIBGADU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgadu
