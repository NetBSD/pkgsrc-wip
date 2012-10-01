# $NetBSD: buildlink3.mk,v 1.1 2012/10/01 13:42:30 othyro Exp $

BUILDLINK_TREE+=	tk85-itk

.if !defined(TK85_ITK_BUILDLINK3_MK)
TK85_ITK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk85-itk+=	tk85-itk>=3.3
BUILDLINK_PKGSRCDIR.tk85-itk?=	../../wip/tk85-itk

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../wip/tcl85-itcl/buildlink3.mk"
.include "../../wip/tcl85/buildlink3.mk"
.include "../../wip/tk85/buildlink3.mk"
.endif	# TK85_ITK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk85-itk
