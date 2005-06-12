# $NetBSD: buildlink3.mk,v 1.2 2005/06/12 23:51:28 kristerw Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SIMGEAR_BUILDLINK3_MK:=	${SIMGEAR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	simgear
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsimgear}
BUILDLINK_PACKAGES+=	simgear

.if !empty(SIMGEAR_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.simgear+=	simgear>=0.3.4
BUILDLINK_PKGSRCDIR.simgear?=	../../wip/simgear
BUILDLINK_DEPMETHOD.simgear?=	build
.endif	# SIMGEAR_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
