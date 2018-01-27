# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/05/22 23:08:12 jihbed Exp $

BUILDLINK_TREE+=	libmopac7

.if !defined(LIBMOPAC7_BUILDLINK3_MK)
LIBMOPAC7_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmopac7+=	libmopac7>=1.11
BUILDLINK_PKGSRCDIR.libmopac7?=		../../wip/mopac7
.endif	# LIBMOPAC7_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmopac7
