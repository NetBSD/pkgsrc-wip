# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/23 13:00:58 phonohawk Exp $

BUILDLINK_TREE+=	hs-gnuplot

.if !defined(HS_GNUPLOT_BUILDLINK3_MK)
HS_GNUPLOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-gnuplot+=	hs-gnuplot>=0.3.3
BUILDLINK_PKGSRCDIR.hs-gnuplot?=	../../wip/hs-gnuplot

.include "../../wip/hs-monoid-transformer/buildlink3.mk"
.include "../../wip/hs-time/buildlink3.mk"
.include "../../wip/hs-utility-ht/buildlink3.mk"
.endif	# HS_GNUPLOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-gnuplot
