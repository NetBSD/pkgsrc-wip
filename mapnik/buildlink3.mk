# $NetBSD: buildlink3.mk,v 1.2 2007/09/23 13:57:19 tnn2 Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MAPNIK_BUILDLINK3_MK:=	${MAPNIK_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	mapnik
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmapnik}
BUILDLINK_PACKAGES+=	mapnik
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}mapnik

.if ${MAPNIK_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.mapnik+=	mapnik>=0.4.0
BUILDLINK_PKGSRCDIR.mapnik?=	../../wip/mapnik
.endif	# MAPNIK_BUILDLINK3_MK

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../graphics/jpeg/buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
#.include "../../graphics/tiff/buildlink3.mk"
#.include "../../misc/proj/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
