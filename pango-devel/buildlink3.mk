# $NetBSD: buildlink3.mk,v 1.1 2004/03/17 11:48:56 mpasternak Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.2.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PANGO_BUILDLINK3_MK:=	${PANGO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pango
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npango}
BUILDLINK_PACKAGES+=	pango

.if !empty(PANGO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pango+=	pango>=1.4.0
BUILDLINK_PKGSRCDIR.pango?=	../../wip/pango-devel

.include "../../wip/glib2-devel/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"

.endif	# PANGO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
