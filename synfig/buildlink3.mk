# $NetBSD: buildlink3.mk,v 1.8 2011/03/21 16:43:49 phonohawk Exp $

BUILDLINK_TREE+=	synfig

.if !defined(SYNFIG_BUILDLINK3_MK)
SYNFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.synfig+=	synfig>=0.62.02
BUILDLINK_PKGSRCDIR.synfig?=	../../wip/synfig

.include "../../devel/ETL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.endif	# SYNFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-synfig
