# $NetBSD: buildlink3.mk,v 1.19 2014/01/01 11:52:03 wiz Exp $

BUILDLINK_TREE+=	compat32_libxslt

.if !defined(COMPAT32_LIBXSLT_BUILDLINK3_MK)
COMPAT32_LIBXSLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat32_libxslt+=	compat32_libxslt>=1.1.8
BUILDLINK_ABI_DEPENDS.compat32_libxslt+=	compat32_libxslt>=1.1.28nb2
BUILDLINK_PKGSRCDIR.compat32_libxslt?=		../../wip/compat32_libxslt
BUILDLINK.LIBDIRS.compat32_libxslt=		emul/netbsd32/lib

.include "../../wip/compat32_libgcrypt/buildlink3.mk"
.include "../../wip/compat32_libxml2/buildlink3.mk"
.endif # COMPAT32_LIBXSLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat32_libxslt
