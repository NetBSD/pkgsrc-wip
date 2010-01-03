# $NetBSD: buildlink3.mk,v 1.6 2010/01/03 15:52:45 pallegra Exp $

BUILDLINK_TREE+=	MesaLib

.if !defined(MESALIB_BUILDLINK3_MK)
MESALIB_BUILDLINK3_MK:=

#BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=7.7
BUILDLINK_PKGSRCDIR.MesaLib?=	../../wip/MesaLib

.include "../../wip/dri/buildlink3.mk"
.include "../../wip/glw/buildlink3.mk"
.include "../../wip/gl/buildlink3.mk"
.endif	# MESALIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-MesaLib
