# $NetBSD: buildlink3.mk,v 1.6 2011/03/22 06:10:38 phonohawk Exp $

BUILDLINK_TREE+=	synfigstudio

.if !defined(SYNFIGSTUDIO_BUILDLINK3_MK)
SYNFIGSTUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.synfigstudio+=	synfigstudio>=0.62.02
BUILDLINK_PKGSRCDIR.synfigstudio?=	../../wip/synfigstudio

.include "../../wip/ETL/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../wip/synfig/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# SYNFIGSTUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-synfigstudio
