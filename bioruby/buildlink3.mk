# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/02/25 20:18:24 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.bioruby?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BIORUBY_BUILDLINK3_MK:=	${BIORUBY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	bioruby
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nbioruby}
BUILDLINK_PACKAGES+=	bioruby

.if !empty(BIORUBY_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.bioruby+=	bioruby>=0.4.0
BUILDLINK_PKGSRCDIR.bioruby?=	../../wip/bioruby
.endif	# BIORUBY_BUILDLINK3_MK

.include "../../lang/ruby-base/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
