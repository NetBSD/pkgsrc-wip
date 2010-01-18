# $NetBSD: buildlink3.mk,v 1.4 2010/01/18 09:38:33 thomasklausner Exp $

BUILDLINK_TREE+=	spandsp

.if !defined(SPANDSP_BUILDLINK3_MK)
SPANDSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spandsp+=	spandsp>=0.0.6pre7
BUILDLINK_ABI_DEPENDS.spandsp?=	spandsp>=0.0.6pre7nb1
BUILDLINK_PKGSRCDIR.spandsp?=	../../wip/spandsp-current

.include "../../graphics/tiff/buildlink3.mk"
.endif # SPANDSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-spandsp
