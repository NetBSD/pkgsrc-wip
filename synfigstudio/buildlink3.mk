# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/07/21 01:05:11 phonohawk Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SYNFIGSTUDIO_BUILDLINK3_MK:=	${SYNFIGSTUDIO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	synfigstudio
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsynfigstudio}
BUILDLINK_PACKAGES+=	synfigstudio
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}synfigstudio

.if ${SYNFIGSTUDIO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.synfigstudio+=	synfigstudio>=0.61.08
BUILDLINK_PKGSRCDIR.synfigstudio?=	../../wip/synfigstudio
.endif	# SYNFIGSTUDIO_BUILDLINK3_MK

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../wip/ETL/buildlink3.mk"
.include "../../wip/synfig/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
