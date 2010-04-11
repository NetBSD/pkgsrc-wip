# $NetBSD: buildlink3.mk,v 1.2 2010/04/11 09:36:06 obache Exp $

BUILDLINK_TREE+=	libbind

.if !defined(LIBBIND_BUILDLINK3_MK)
LIBBIND_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libbind?=	build
BUILDLINK_API_DEPENDS.libbind+=	libbind>=6.0
BUILDLINK_PKGSRCDIR.libbind?=	../../wip/libbind
.endif	# LIBBIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbind
