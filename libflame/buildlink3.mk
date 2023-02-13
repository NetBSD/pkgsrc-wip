# $NetBSD: buildlink3.mk,v 1.1 2020/11/05 16:31:45 bacon Exp $

BUILDLINK_TREE+=	libflame

.if !defined(LIBFLAME_BUILDLINK3_MK)
LIBFLAME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libflame+=	libflame>=5.2.0
BUILDLINK_PKGSRCDIR.libflame?=		../../wip/libflame
.include "../../wip/blis/buildlink3.mk"
.endif	# LIBFLAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-libflame
