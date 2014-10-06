# $NetBSD: buildlink3.mk,v 1.1 2014/10/06 15:10:50 makoto Exp $

BUILDLINK_TREE+=	gr-fcdproplus

.if !defined(GR_FCDPROPLUS_BUILDLINK3_MK)
GR_FCDPROPLUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gr-fcdproplus+=	gr-fcdproplus>=3.6
BUILDLINK_ABI_DEPENDS.gr-fcdproplus+=	gr-fcdproplus>=3.6
BUILDLINK_PKGSRCDIR.gr-fcdproplus?=	../../wip/gr-fcdproplus
.endif # GR_FCDPROPLUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gr-fcdproplus
