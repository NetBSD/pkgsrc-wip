# $NetBSD: buildlink3.mk,v 1.2 2011/11/22 17:11:04 ryo-on Exp $

BUILDLINK_TREE+=	libisoburn

.if !defined(LIBISOBURN_BUILDLINK3_MK)
LIBISOBURN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libisoburn+=	libisoburn>=1.1.8
BUILDLINK_PKGSRCDIR.libisoburn?=	../../wip/libisoburn

.include "../../wip/libisofs/buildlink3.mk"
.include "../../wip/libburn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBISOBURN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libisoburn
