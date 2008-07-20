# $NetBSD: buildlink3.mk,v 1.2 2008/07/20 15:43:34 phonohawk Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SYNFIG_BUILDLINK3_MK:=	${SYNFIG_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	synfig
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsynfig}
BUILDLINK_PACKAGES+=	synfig
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}synfig

.if ${SYNFIG_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.synfig+=	synfig>=0.61.08
BUILDLINK_PKGSRCDIR.synfig?=	../../wip/synfig
.endif	# SYNFIG_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../wip/ETL/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
