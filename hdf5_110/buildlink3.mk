# $NetBSD: buildlink3.mk,v 1.16 2021/06/07 11:52:48 adam Exp $

BUILDLINK_TREE+=	hdf5_110

.if !defined(HDF5_110_BUILDLINK3_MK)
HDF5_110_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hdf5_110+=	hdf5_110>=1.10.7
BUILDLINK_ABI_DEPENDS.hdf5_110+=	hdf5_110>=1.10.11
BUILDLINK_PKGSRCDIR.hdf5_110?=		../../wip/hdf5_110

pkgbase := hdf5_110
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.hdf5_110:Mszip}
.include "../../archivers/libaec/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.endif # HDF5_110_BUILDLINK3_MK

BUILDLINK_TREE+=	-hdf5_110
