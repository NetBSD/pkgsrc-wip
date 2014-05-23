# $NetBSD: buildlink3.mk,v 1.3 2014/05/23 21:49:03 szptvlfn Exp $

BUILDLINK_TREE+=	hs-dyre

.if !defined(HS_DYRE_BUILDLINK3_MK)
HS_DYRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dyre+=	hs-dyre>=0.8.6
BUILDLINK_PKGSRCDIR.hs-dyre?=	../../wip/hs-dyre

.include "../../wip/hs-executable-path/buildlink3.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../wip/hs-io-storage/buildlink3.mk"
.include "../../wip/hs-xdg-basedir/buildlink3.mk"
.endif	# HS_DYRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dyre
