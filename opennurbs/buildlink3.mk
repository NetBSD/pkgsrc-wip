# $NetBSD: buildlink3.mk,v 1.1 2013/03/03 21:15:03 othyro Exp $

BUILDLINK_TREE+=	opennurbs

.if !defined(OPENNURBS_BUILDLINK3_MK)
OPENNURBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opennurbs+=	opennurbs>=20130711
BUILDLINK_PKGSRCDIR.opennurbs?=		../../wip/opennurbs

.include "../../devel/zlib/buildlink3.mk"
.endif	# OPENNURBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-opennurbs
