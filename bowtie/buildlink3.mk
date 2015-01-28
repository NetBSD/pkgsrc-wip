# $NetBSD: buildlink3.mk,v 1.1 2015/01/28 20:52:06 outpaddling Exp $

BUILDLINK_TREE+=	bowtie

.if !defined(BOWTIE_BUILDLINK3_MK)
BOWTIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bowtie+=	bowtie>=1.0.1
BUILDLINK_PKGSRCDIR.bowtie?=	../../wip/bowtie
.endif	# BOWTIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-bowtie
