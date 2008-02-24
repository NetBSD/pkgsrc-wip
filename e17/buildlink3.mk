# $NetBSD: buildlink3.mk,v 1.2 2008/02/24 05:01:56 shindenmorr Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.e17?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
E17_BUILDLINK3_MK:=	${E17_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	e17
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ne17}
BUILDLINK_PACKAGES+=	e17
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}e17

.if ${E17_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.e17+=	e17>=0.16.999.042
BUILDLINK_PKGSRCDIR.e17?=	../../wip/e17
.endif	# E17_BUILDLINK3_MK

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
