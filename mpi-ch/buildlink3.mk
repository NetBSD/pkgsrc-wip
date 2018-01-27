# $NetBSD: buildlink3.mk,v 1.10 2013/03/07 19:08:45 asau Exp $

BUILDLINK_TREE+=	mpich

.if !defined(MPICH_BUILDLINK3_MK)
MPICH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpich+=	mpich>=3
BUILDLINK_PKGSRCDIR.mpich?=	../../wip/mpi-ch
BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/mpich/lib
BUILDLINK_PASSTHRU_RPATHDIRS+=	${PREFIX}/mpich/lib

.include "../../parallel/openpa/buildlink3.mk"
.endif	# MPICH_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpich
