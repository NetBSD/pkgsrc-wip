# $NetBSD: buildlink3.mk,v 1.1 2004/03/17 11:48:56 mpasternak Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.2.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
ATK_BUILDLINK3_MK:=	${ATK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	atk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Natk}
BUILDLINK_PACKAGES+=	atk

.if !empty(ATK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.atk+=	atk>=1.6.0
BUILDLINK_PKGSRCDIR.atk?=	../../wip/atk-devel

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/glib2-devel/buildlink3.mk"

.endif	# ATK_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
