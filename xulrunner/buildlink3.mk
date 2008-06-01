# $NetBSD: buildlink3.mk,v 1.1 2008/06/01 15:22:33 tnn2 Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XULRUNNER_BUILDLINK3_MK:=	${XULRUNNER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xulrunner
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxulrunner}
BUILDLINK_PACKAGES+=	xulrunner
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xulrunner

.if ${XULRUNNER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xulrunner+=	xulrunner>=1.9rc1
BUILDLINK_PKGSRCDIR.xulrunner?=	../../wip/xulrunner
.endif	# XULRUNNER_BUILDLINK3_MK

#.include "../../net/libIDL/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"
#.include "../../x11/libXt/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
