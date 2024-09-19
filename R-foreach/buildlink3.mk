# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/05/03 22:37:49 bubuchka Exp $

BUILDLINK_TREE+=	Rforeach

.if !defined(RFOREACH_BUILDLINK3_MK)
RFOREACH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Rforeach+=	R-foreach>=1.4.0
BUILDLINK_ABI_DEPENDS.Rforeach+=	R-foreach>=1.4.0
BUILDLINK_PKGSRCDIR.Rforeach?=		../../wip/R-foreach
.endif # RFOREACH_BUILDLINK3_MK

BUILDLINK_TREE+=	-Rforeach
