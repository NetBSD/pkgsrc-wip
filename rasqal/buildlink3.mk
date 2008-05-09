# $NetBSD: buildlink3.mk,v 1.3 2008/05/09 21:58:13 mwdavies Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RASQAL_BUILDLINK3_MK:=	${RASQAL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	rasqal
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nrasqal}
BUILDLINK_PACKAGES+=	rasqal
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}rasqal

.if ${RASQAL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.rasqal+=	rasqal>=0.9.14
BUILDLINK_ABI_DEPENDS.rasqal?=	rasqal>=0.9.14nb1
BUILDLINK_PKGSRCDIR.rasqal?=	../../wip/rasqal
.endif	# RASQAL_BUILDLINK3_MK

.include "../../textproc/raptor/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
