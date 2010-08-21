# $NetBSD: buildlink3.mk,v 1.1 2010/08/21 14:25:22 cheusov Exp $

BUILDLINK_TREE+=	openbabel

.if !defined(OPENBABEL_BUILDLINK3_MK)
OPENBABEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openbabel+=	openbabel>=2.2.3
BUILDLINK_PKGSRCDIR.openbabel?=	../../wip/openbabel


.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# OPENBABEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-openbabel
