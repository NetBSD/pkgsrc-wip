# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	hs-magic

.if !defined(HS_MAGIC_BUILDLINK3_MK)
HS_MAGIC_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-magic?=	build
BUILDLINK_API_DEPENDS.hs-magic+=	hs-magic>=1.0.7
BUILDLINK_PKGSRCDIR.hs-magic?=	../../wip/hs-magic

.include "../../sysutils/file/buildlink3.mk"
.endif # HS_MAGIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-magic
