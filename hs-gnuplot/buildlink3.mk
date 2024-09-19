# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:13 szptvlfn Exp $

BUILDLINK_TREE+=	hs-gnuplot

.if !defined(HS_GNUPLOT_BUILDLINK3_MK)
HS_GNUPLOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-gnuplot+=	hs-gnuplot>=0.3.3
BUILDLINK_ABI_DEPENDS.hs-gnuplot+=	hs-gnuplot>=0.3.3
BUILDLINK_PKGSRCDIR.hs-gnuplot?=	../../wip/hs-gnuplot

.include "../../wip/hs-monoid-transformer/buildlink3.mk"
.include "../../devel/hs-utility-ht/buildlink3.mk"
.endif	# HS_GNUPLOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-gnuplot
