# $NetBSD$

BUILDLINK_TREE+=	libvirt

.if !defined(LIBVIRT_BUILDLINK3_MK)
LIBVIRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvirt+=	libvirt>=5.4.0
BUILDLINK_PKGSRCDIR.libvirt?=	../../wip/libvirt

.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.endif	# LIBVIRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvirt
