# $NetBSD: buildlink3.mk,v 1.3 2014/09/09 11:32:55 fhajny Exp $

BUILDLINK_TREE+=	liblognorm

.if !defined(LIBLOGNORM_BUILDLINK3_MK)
LIBLOGNORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblognorm+=	liblognorm>=0.3.1<1.0.0
BUILDLINK_PKGSRCDIR.liblognorm=		../../wip/liblognorm

.endif # LIBLOGNORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblognorm
