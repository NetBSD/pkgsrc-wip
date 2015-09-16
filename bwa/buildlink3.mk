# $NetBSD: buildlink3.mk,v 1.1 2015/09/16 14:24:01 outpaddling Exp $

BUILDLINK_TREE+=	bwa

.if !defined(BWA_BUILDLINK3_MK)
BWA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bwa+=	bwa>=0.7.9a
BUILDLINK_PKGSRCDIR.bwa?=	../../wip/bwa

.include "../../devel/zlib/buildlink3.mk"
.endif	# BWA_BUILDLINK3_MK

BUILDLINK_TREE+=	-bwa
