# $NetBSD: buildlink3.mk,v 1.5 2008/01/26 02:52:44 obache Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MING_BUILDLINK3_MK:=	${MING_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ming
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nming}
BUILDLINK_PACKAGES+=	ming
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ming

.if ${MING_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ming+=	ming>=0.4.0beta5
BUILDLINK_PKGSRCDIR.ming?=	../../wip/ming
.endif	# MING_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
