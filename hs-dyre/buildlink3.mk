# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/08 10:10:44 phonohawk Exp $

BUILDLINK_TREE+=	hs-dyre

.if !defined(HS_DYRE_BUILDLINK3_MK)
HS_DYRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dyre+=	hs-dyre>=0.8
BUILDLINK_PKGSRCDIR.hs-dyre?=	../../wip/hs-dyre

.include "../../wip/hs-binary/buildlink3.mk"
.include "../../wip/hs-executable-path/buildlink3.mk"
.include "../../wip/hs-ghc-paths/buildlink3.mk"
.include "../../wip/hs-io-storage/buildlink3.mk"
.include "../../wip/hs-xdg-basedir/buildlink3.mk"
.endif	# HS_DYRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dyre
