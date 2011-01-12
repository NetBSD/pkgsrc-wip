# $NetBSD: buildlink3.mk,v 1.8 2011/01/12 05:56:33 phonohawk Exp $

BUILDLINK_TREE+=	hs-darcs

.if !defined(HS_DARCS_BUILDLINK3_MK)
HS_DARCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-darcs+=	hs-darcs>=2.5
BUILDLINK_PKGSRCDIR.hs-darcs?=	../../wip/darcs

.include "../../wip/hs-hashed-storage/buildlink3.mk"
.include "../../wip/hs-haskeline/buildlink3.mk"
.include "../../wip/hs-html/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../wip/hs-tar/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.endif	# HS_DARCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-darcs
