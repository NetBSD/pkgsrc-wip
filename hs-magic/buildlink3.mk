# $NetBSD: buildlink3.mk,v 1.3 2009/07/27 04:30:38 phonohawk Exp $

BUILDLINK_TREE+=	hs-magic

.if !defined(HS_MAGIC_BUILDLINK3_MK)
HS_MAGIC_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-magic?=	build
BUILDLINK_API_DEPENDS.hs-magic+=	hs-magic>=1.0.7nb1
BUILDLINK_PKGSRCDIR.hs-magic?=	../../wip/hs-magic

.include "../../sysutils/file/buildlink3.mk"
.endif # HS_MAGIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-magic
