# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/02/25 02:04:07 obache Exp $

BUILDLINK_TREE+=	gpac

.if !defined(GPAC_BUILDLINK3_MK)
GPAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpac+=	gpac>=0.4.5
BUILDLINK_PKGSRCDIR.gpac?=	../../multimedia/gpac
.endif # GPAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpac
