# $NetBSD: buildlink3.mk,v 1.3 2014/02/03 09:48:00 othyro Exp $

BUILDLINK_TREE+=	libbfio

.if !defined(LIBBFIO_BUILDLINK3_MK)
LIBBFIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbfio+=	libbfio>=20120425
BUILDLINK_PKGSRCDIR.libbfio?=	../../wip/libbfio

.include "../../wip/libcthreads/buildlink3.mk"
.include "../../wip/libcfile/buildlink3.mk"
.include "../../wip/libuna/buildlink3.mk"
.include "../../wip/libcpath/buildlink3.mk"
.include "../../wip/libcsplit/buildlink3.mk"
.include "../../wip/libcnotify/buildlink3.mk"
.include "../../wip/libcdata/buildlink3.mk"
.include "../../wip/libclocale/buildlink3.mk"
.include "../../wip/libcerror/buildlink3.mk"
.endif	# LIBBFIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbfio
