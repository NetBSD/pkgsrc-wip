# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:09:59 szptvlfn Exp $

BUILDLINK_TREE+=	hs-ConfigFile

.if !defined(HS_CONFIGFILE_BUILDLINK3_MK)
HS_CONFIGFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ConfigFile+=	hs-ConfigFile>=1.0.6
BUILDLINK_ABI_DEPENDS.hs-ConfigFile+=	hs-ConfigFile>=1.0.6
BUILDLINK_PKGSRCDIR.hs-ConfigFile?=	../../wip/hs-ConfigFile

.include "../../wip/hs-MissingH/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_CONFIGFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ConfigFile
