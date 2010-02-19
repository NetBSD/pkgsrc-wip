# $NetBSD: buildlink3.mk,v 1.7 2010/02/19 09:52:53 phonohawk Exp $

BUILDLINK_TREE+=	darcs

.if !defined(DARCS_BUILDLINK3_MK)
DARCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.darcs+=	darcs>=2.3.99.2nb1
BUILDLINK_PKGSRCDIR.darcs?=	../../wip/darcs

.include "../../wip/hs-hashed-storage/buildlink3.mk"
.include "../../wip/hs-haskeline/buildlink3.mk"
.include "../../wip/hs-html/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.endif	# DARCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-darcs
