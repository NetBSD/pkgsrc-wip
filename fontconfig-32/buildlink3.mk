# $NetBSD: buildlink3.mk,v 1.36 2018/08/31 09:06:07 tnn Exp $

BUILDLINK_TREE+=	compat32_fontconfig

.if !defined(COMPAT32_FONTCONFIG_BUILDLINK3_MK)
COMPAT32_FONTCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat32_fontconfig+=	compat32_fontconfig>=2.10.93
BUILDLINK_ABI_DEPENDS.compat32_fontconfig+=	compat32_fontconfig>=2.13.0
BUILDLINK_PKGSRCDIR.compat32_fontconfig?=	../../wip/fontconfig-32
BUILDLINK_LIBDIRS.compat32_fontconfig?=		emul/netbsd32/lib/fontconfig
BUILDLINK_INCDIRS.compat32_fontconfig?=		emul/netbsd32/include

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/libuuid-32/buildlink3.mk"
.include "../../wip/freetype2-32/buildlink3.mk"
.include "../../wip/expat-32/buildlink3.mk"
.endif # COMPAT32_FONTCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat32_fontconfig
