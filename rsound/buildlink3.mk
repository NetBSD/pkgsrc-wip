# $NetBSD: buildlink3.mk,v 1.1 2012/10/03 22:45:58 othyro Exp $

BUILDLINK_TREE+=	rsound

.if !defined(RSOUND_BUILDLINK3_MK)
RSOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rsound+=	rsound>=1.1
BUILDLINK_PKGSRCDIR.rsound?=	../../wip/rsound
.endif	# RSOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-rsound
