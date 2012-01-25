# $NetBSD: buildlink3.mk,v 1.1 2012/01/25 10:54:58 mwdavies Exp $

BUILDLINK_TREE+=	libkipi

.if !defined(LIBKIPI_BUILDLINK3_MK)
LIBKIPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkipi+=	libkipi>=4.8.0
BUILDLINK_PKGSRCDIR.libkipi?=	../../wip/libkipi

.include "../../wip/kdelibs4/buildlink3.mk"
.endif	# LIBKIPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkipi
