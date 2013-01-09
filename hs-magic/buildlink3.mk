# $NetBSD: buildlink3.mk,v 1.4 2013/01/09 23:29:38 szptvlfn Exp $

BUILDLINK_TREE+=	hs-magic

.if !defined(HS_MAGIC_BUILDLINK3_MK)
HS_MAGIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-magic+=	hs-magic>=1.0.7nb1
BUILDLINK_PKGSRCDIR.hs-magic?=	../../wip/hs-magic

.include "../../sysutils/file/buildlink3.mk"
.endif # HS_MAGIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-magic
