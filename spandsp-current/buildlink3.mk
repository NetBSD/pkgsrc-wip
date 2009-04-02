# $NetBSD: buildlink3.mk,v 1.3 2009/04/02 09:08:50 x400 Exp $

BUILDLINK_TREE+=	spandsp

.if !defined(SPANDSP_BUILDLINK3_MK)
SPANDSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spandsp+=	spandsp>=0.0.6pre7
BUILDLINK_PKGSRCDIR.spandsp?=	../../wip/spandsp-current

.include "../../graphics/tiff/buildlink3.mk"
.endif # SPANDSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-spandsp
