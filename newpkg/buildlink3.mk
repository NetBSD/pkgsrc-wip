# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/02/05 00:02:32 pseudo_anim Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.guichan-0.6.0?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GUICHAN_0.6.0_BUILDLINK3_MK:=	${GUICHAN_0.6.0_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	guichan-0.6.0
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nguichan-0.6.0}
BUILDLINK_PACKAGES+=	guichan-0.6.0
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}guichan-0.6.0

.if ${GUICHAN_0.6.0_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.guichan-0.6.0+=	guichan-0.6.0>=src
BUILDLINK_PKGSRCDIR.guichan-0.6.0?=	../../wip/guichan
.endif	# GUICHAN_0.6.0_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/SDL/buildlink3.mk"
#.include "../../graphics/SDL_image/buildlink3.mk"
#.include "../../audio/SDL_mixer/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
