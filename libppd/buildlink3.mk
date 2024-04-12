# $NetBSD$

BUILDLINK_TREE+=	libppd

.if !defined(LIBPPD_BUILDLINK3_MK)
LIBPPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libppd+=	libppd>=2.0.0
BUILDLINK_ABI_DEPENDS.libppd+=	libppd>=2.0.0
BUILDLINK_PKGSRCDIR.libppd?=	../../wip/libppd

pkgbase := libppd
.include "../../mk/pkg-build-options.mk"

.include "../../wip/libcupsfilters/buildlink3.mk"
.endif # LIBPPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libppd
