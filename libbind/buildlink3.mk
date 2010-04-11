# $NetBSD: buildlink3.mk,v 1.3 2010/04/11 09:51:09 obache Exp $

BUILDLINK_TREE+=	libbind

.if !defined(LIBBIND_BUILDLINK3_MK)
LIBBIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbind+=	libbind>=6.0
BUILDLINK_PKGSRCDIR.libbind?=	../../wip/libbind
.endif	# LIBBIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbind
