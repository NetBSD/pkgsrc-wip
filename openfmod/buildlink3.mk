# $NetBSD$
BUILDLINK_TREE+=	openfmod

.if !defined(OPENFMOD_BUILDLINK3_MK)
OPENFMOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openfmod+=	openfmod>=0.0.20201109
BUILDLINK_PKGSRCDIR.openfmod?=	../../wip/openfmod

.include "../../textproc/jansson/buildlink3.mk"
.include "../../wip/gorilla-audio/buildlink3.mk"
.endif	# OPENFMOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-openfmod
