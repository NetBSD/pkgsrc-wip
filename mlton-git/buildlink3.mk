# $NetBSD: buildlink3.mk,v 1.3 2012/11/23 22:33:44 othyro Exp $

BUILDLINK_DEPMETHOD.mlton?=	build

BUILDLINK_TREE+=	mlton

.if !defined(MLTON_BUILDLINK3_MK)
MLTON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mlton+=	mlton-*
BUILDLINK_PKGSRCDIR.mlton?=	../../wip/mlton-git
BUILDLINK_INCDIRS.mlton= lib/mlton/include
BUILDLINK_LIBDIRS.mlton= lib/mlton/self
#BUILDLINK_CONTENTS_FILTER.mlton= ${EGREP} '.*\.a$$|.*\.h$$'
.include "../../devel/gmp/buildlink3.mk"
.endif	# MLTON_BUILDLINK3_MK

BUILDLINK_TREE+=	-mlton
