# $NetBSD: buildlink3.mk,v 1.1 2005/12/16 10:13:23 poppnk Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
COMMONCPP2_BUILDLINK3_MK:=	${COMMONCPP2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	commoncpp2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncommoncpp2}
BUILDLINK_PACKAGES+=	commoncpp2

.if !empty(COMMONCPP2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.commoncpp2+=	commoncpp2>=1.3.16
BUILDLINK_PKGSRCDIR.commoncpp2?=	../../wip/commoncpp2
.endif	# COMMONCPP2_BUILDLINK3_MK

#.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
