# $NetBSD: buildlink3.mk,v 1.1 2013/06/09 21:56:24 othyro Exp $

BUILDLINK_TREE+=	libcfile

.if !defined(LIBCFILE_BUILDLINK3_MK)
LIBCFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcfile+=	libcfile>=20130509
BUILDLINK_PKGSRCDIR.libcfile?=		../../wip/libcfile

.include "../../wip/libuna/buildlink3.mk"
.include "../../wip/libcnotify/buildlink3.mk"
.include "../../wip/libclocale/buildlink3.mk"
.include "../../wip/libcerror/buildlink3.mk"
.endif	# LIBCFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcfile
