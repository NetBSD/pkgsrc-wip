# $NetBSD: buildlink3.mk,v 1.18 2012/06/14 07:39:37 sbd Exp $

BUILDLINK_TREE+=	compat32_libxml2

.if !defined(compat32_libxml2_BUILDLINK3_MK)
compat32_libxml2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat32_libxml2+=	compat32_libxml2>=2.6.2
BUILDLINK_ABI_DEPENDS.compat32_libxml2+=	compat32_libxml2>=2.8.0nb2
#BUILDLINK_PKGSRCDIR.compat32_libxml2?=		../../textproc/compat32_libxml2
BUILDLINK_PKGSRCDIR.compat32_libxml2?=		../../wip/compat32_libxml2
BUILDLINK_LIBDIRS.compat32_libxml2=		emul/netbsd32/lib
BUILDLINK_INCDIRS.compat32_libxml2=		emul/netbsd32/include

BUILDLINK_FILES.compat32_libxml2+=		emul/netbsd32/bin/xml2-config

USE_FEATURES+=		glob

# We need the non-compat version for headers.
BUILDLINK_DEPMETHOD.libxml2+=	build
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # COMPAT32_LIBXML2_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat32_libxml2
