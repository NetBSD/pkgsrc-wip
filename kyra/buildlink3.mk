# $NetBSD: buildlink3.mk,v 1.1 2004/03/07 02:38:00 mpasternak Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.2.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KYRA_BUILDLINK3_MK:=	${KYRA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kyra
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkyra}
BUILDLINK_PACKAGES+=	kyra

.if !empty(KYRA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kyra+=	kyra>=1.6.5
BUILDLINK_PKGSRCDIR.kyra?=	../../wip/kyra

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"

.endif	# KYRA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
