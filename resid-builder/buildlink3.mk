# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:52 jsonn Exp $
#

BUILDLINK_TREE+=	resid-builder

.if !defined(RESID_BUILDER_BUILDLINK3_MK)
RESID_BUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.resid-builder+=	resid-builder>=20060528
BUILDLINK_PKGSRCDIR.resid-builder?=	../../wip/resid-builder

.include "../../wip/libsidplay2/buildlink3.mk"
.endif # RESID_BUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-resid-builder
