# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/22 21:07:44 outpaddling Exp $

BUILDLINK_TREE+=	meep

.if !defined(MEEP_BUILDLINK3_MK)
MEEP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.meep+=	meep>=1.1.1
BUILDLINK_PKGSRCDIR.meep?=	../../jb-wip/meep

.include "../../jb-wip/harminv/buildlink3.mk"
.include "../../jb-wip/libctl/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# MEEP_BUILDLINK3_MK

BUILDLINK_TREE+=	-meep
