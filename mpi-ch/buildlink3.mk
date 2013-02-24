# $NetBSD: buildlink3.mk,v 1.9 2013/02/24 19:15:53 asau Exp $

BUILDLINK_TREE+=	mpich

.if !defined(MPICH_BUILDLINK3_MK)
MPICH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpich+=	mpich>=3
BUILDLINK_PKGSRCDIR.mpich?=	../../wip/mpi-ch

.include "../../parallel/openpa/buildlink3.mk"
.endif	# MPICH_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpich
