# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/03/07 02:46:24 mpasternak Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.2.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KYRA2_BUILDLINK3_MK:=	${KYRA2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kyra2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkyra2}
BUILDLINK_PACKAGES+=	kyra2

.if !empty(KYRA2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kyra2+=	kyra2>=2.0.7
BUILDLINK_PKGSRCDIR.kyra2?=	../../wip/kyra2

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"

.endif	# KYRA2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
