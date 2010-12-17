# $NetBSD: buildlink3.mk,v 1.8 2010/12/17 03:06:42 asau Exp $

BUILDLINK_TREE+=	mpich2

.if !defined(MPICH2_BUILDLINK3_MK)
MPICH2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpich2+=	mpich2>=1.2.99.6307
BUILDLINK_PKGSRCDIR.mpich2?=	../../wip/mpi-ch

.include "../../parallel/openpa/buildlink3.mk"
.endif	# MPICH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpich2
