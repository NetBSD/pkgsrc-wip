# $NetBSD: synce-rra.bl3.mk,v 1.1.1.1 2008/12/04 23:11:11 shattered Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.synce-rra?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SYNCE_RRA_BUILDLINK3_MK:=	${SYNCE_RRA_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	synce-rra
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsynce-rra}
BUILDLINK_PACKAGES+=	synce-rra
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}synce-rra

.if ${SYNCE_RRA_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.synce-rra+=	synce-rra>=0.9.1nb2
BUILDLINK_PKGSRCDIR.synce-rra?=	../../comms/synce-rra
.endif	# SYNCE_RRA_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../comms/synce-librapi2/buildlink3.mk"
#.include "../../comms/synce-libsynce/buildlink3.mk"
#.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libmimedir/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
