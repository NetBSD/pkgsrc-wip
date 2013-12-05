# $NetBSD: buildlink3.mk,v 1.9 2013/12/05 05:34:20 phonohawk Exp $

BUILDLINK_TREE+=	darcs

.if !defined(DARCS_BUILDLINK3_MK)
DARCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.darcs+=	darcs>=2.8.4
BUILDLINK_PKGSRCDIR.darcs?=	../../wip/darcs

.include "../../converters/libiconv/buildlink3.mk"
.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-hashed-storage/buildlink3.mk"
.include "../../wip/hs-haskeline/buildlink3.mk"
.include "../../wip/hs-html/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-random/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../wip/hs-tar/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.endif	# DARCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-darcs
