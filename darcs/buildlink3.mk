# $NetBSD: buildlink3.mk,v 1.17 2014/08/29 14:09:59 szptvlfn Exp $

BUILDLINK_TREE+=	darcs

.if !defined(DARCS_BUILDLINK3_MK)
DARCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.darcs+=	darcs>=2.8.4
BUILDLINK_ABI_DEPENDS.darcs+=	darcs>=2.8.4
BUILDLINK_PKGSRCDIR.darcs?=	../../wip/darcs

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-hashed-storage/buildlink3.mk"
.include "../../wip/hs-html/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../wip/hs-tar/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.endif	# DARCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-darcs
