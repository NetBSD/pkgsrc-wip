# $NetBSD: buildlink3.mk,v 1.0 2024/11/14 16:30:00 dkazankov Exp $

BUILDLINK_TREE+=	polyorb

.if !defined(POLYORB_BUILDLINK3_MK)
POLYORB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polyorb+=	polyorb>=25.0.0
BUILDLINK_PKGSRCDIR.polyorb?=	../../wip/polyorb
BUILDLINK_DEPMETHOD.polyorb?=	build

pkgbase := polyorb
.include "../../mk/pkg-build-options.mk"

.endif

BUILDLINK_TREE+=	-polyorb
