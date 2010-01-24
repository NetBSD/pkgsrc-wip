# $NetBSD: buildlink3.mk,v 1.2 2010/01/24 03:35:26 phonohawk Exp $

BUILDLINK_TREE+=	hs-gnuplot

.if !defined(HS_GNUPLOT_BUILDLINK3_MK)
HS_GNUPLOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-gnuplot+=	hs-gnuplot>=0.3.3
BUILDLINK_PKGSRCDIR.hs-gnuplot?=	../../wip/hs-gnuplot

.include "../../wip/hs-monoid-transformer/buildlink3.mk"
.include "../../wip/hs-utility-ht/buildlink3.mk"
.endif	# HS_GNUPLOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-gnuplot
