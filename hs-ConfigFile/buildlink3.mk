# $NetBSD: buildlink3.mk,v 1.2 2014/05/16 20:47:07 szptvlfn Exp $

BUILDLINK_TREE+=	hs-ConfigFile

.if !defined(HS_CONFIGFILE_BUILDLINK3_MK)
HS_CONFIGFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ConfigFile+=	hs-ConfigFile>=1.0
BUILDLINK_PKGSRCDIR.hs-ConfigFile?=	../../wip/hs-ConfigFile

.include "../../wip/hs-MissingH/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_CONFIGFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ConfigFile
