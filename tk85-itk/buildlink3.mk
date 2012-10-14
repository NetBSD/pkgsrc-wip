# $NetBSD: buildlink3.mk,v 1.3 2012/10/14 13:30:45 thomasklausner Exp $

BUILDLINK_TREE+=	tk85-itk

.if !defined(TK85_ITK_BUILDLINK3_MK)
TK85_ITK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk85-itk+=	tk85-itk>=3.3
BUILDLINK_PKGSRCDIR.tk85-itk?=	../../wip/tk85-itk

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../wip/tcl85-itcl/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif	# TK85_ITK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk85-itk
