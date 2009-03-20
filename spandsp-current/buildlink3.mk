# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:52 jsonn Exp $

BUILDLINK_TREE+=	spandsp

.if !defined(SPANDSP_BUILDLINK3_MK)
SPANDSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spandsp+=	spandsp>=0.0.6pre2
BUILDLINK_PKGSRCDIR.spandsp?=	../../wip/spandsp-current

.include "../../graphics/tiff/buildlink3.mk"
.endif # SPANDSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-spandsp
