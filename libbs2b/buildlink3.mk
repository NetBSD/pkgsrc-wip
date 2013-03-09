# $NetBSD: buildlink3.mk,v 1.1 2013/03/09 15:24:49 othyro Exp $

BUILDLINK_TREE+=	libbs2b

.if !defined(LIBBS2B_BUILDLINK3_MK)
LIBBS2B_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbs2b+=	libbs2b>=3.1.0
BUILDLINK_PKGSRCDIR.libbs2b?=	../../wip/libbs2b

.include "../../audio/libsndfile/buildlink3.mk"
.endif	# LIBBS2B_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbs2b
