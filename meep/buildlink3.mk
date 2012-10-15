# $NetBSD: buildlink3.mk,v 1.3 2012/10/15 19:21:45 asau Exp $

BUILDLINK_TREE+=	meep

.if !defined(MEEP_BUILDLINK3_MK)
MEEP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.meep+=	meep>=1.1.1
BUILDLINK_PKGSRCDIR.meep?=	../../wip/meep

.include "../../math/harminv/buildlink3.mk"
.include "../../wip/libctl/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# MEEP_BUILDLINK3_MK

BUILDLINK_TREE+=	-meep
