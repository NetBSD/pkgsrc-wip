# $NetBSD: buildlink3.mk,v 1.1 2008/09/08 14:54:51 thomasklausner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
KDEEDU4_BUILDLINK3_MK:=	${KDEEDU4_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	kdeedu4
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdeedu4}
BUILDLINK_PACKAGES+=	kdeedu4
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kdeedu4

.if ${KDEEDU4_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.kdeedu4+=	kdeedu4>=4.1.1
BUILDLINK_PKGSRCDIR.kdeedu4?=	../../wip/kdeedu4
.endif	# KDEEDU4_BUILDLINK3_MK

#.include "../../devel/libusb/buildlink3.mk"
#.include "../../devel/readline/buildlink3.mk"
#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
#.include "../../wip/kdebase-runtime4/buildlink3.mk"
#.include "../../wip/kdebase-workspace4/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
