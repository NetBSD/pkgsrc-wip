# $NetBSD: buildlink3.mk,v 1.8 2019/08/11 13:17:49 wiz Exp $

BUILDLINK_TREE+=	superlu

.if !defined(SUPERLU_BUILDLINK3_MK)
SUPERLU_BUILDLINK3_MK:=

# No clue about API/ABI compatibility, but at
# least that matters a bit less with the static lib.
# Since API changed a lot since version 2, use the
# jump to 5.2.1 as new minimum. 
BUILDLINK_API_DEPENDS.superlu+=	superlu>=5.2.1nb8
BUILDLINK_ABI_DEPENDS.superlu?=	superlu>=5.2.1nb8
BUILDLINK_PKGSRCDIR.superlu?=	../../wip/superlu

# When it is the static lib, the users actually have
# to link to blas themselves. Fragile, perhaps.
.include "../../wip/mk/blas.buildlink3.mk"

.endif # SUPERLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-superlu
