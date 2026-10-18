# $NetBSD$

BUILDLINK_TREE+=	gdcm

.if !defined(GDCM_BUILDLINK3_MK)
GDCM_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.gdcm?=	build
BUILDLINK_API_DEPENDS.gdcm+=	gdcm>=3.0.10
BUILDLINK_PKGSRCDIR.gdcm?=	../../wip/gdcm

#.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
#.include "../../security/openssl/buildlink3.mk"
#.include "../../textproc/expat/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../textproc/libxslt/buildlink3.mk"
.endif	# GDCM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdcm
