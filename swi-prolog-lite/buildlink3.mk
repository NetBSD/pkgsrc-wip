# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/04/22 16:46:04 mpasternak Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.swi-prolog-lite?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SWI_PROLOG_LITE_BUILDLINK3_MK:=	${SWI_PROLOG_LITE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	swi-prolog-lite
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nswi-prolog-lite}
BUILDLINK_PACKAGES+=	swi-prolog-lite

.if !empty(SWI_PROLOG_LITE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.swi-prolog-lite+=	swi-prolog-lite>=5.2.9
BUILDLINK_PKGSRCDIR.swi-prolog-lite?=	../../wip/swi-prolog-lite
.endif	# SWI_PROLOG_LITE_BUILDLINK3_MK

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
