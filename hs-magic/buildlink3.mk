# $NetBSD: buildlink3.mk,v 1.5 2014/08/29 14:10:25 szptvlfn Exp $

BUILDLINK_TREE+=	hs-magic

.if !defined(HS_MAGIC_BUILDLINK3_MK)
HS_MAGIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-magic+=	hs-magic>=1.0.8
BUILDLINK_ABI_DEPENDS.hs-magic+=	hs-magic>=1.0.8
BUILDLINK_PKGSRCDIR.hs-magic?=		../../wip/hs-magic

.include "../../sysutils/file/buildlink3.mk"
.endif # HS_MAGIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-magic
