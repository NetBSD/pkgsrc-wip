# $NetBSD: buildlink3.mk,v 1.4 2013/01/07 13:30:24 thomasklausner Exp $

BUILDLINK_TREE+=	tk85-itk

.if !defined(TK85_ITK_BUILDLINK3_MK)
TK85_ITK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk85-itk+=	tk85-itk>=3.3
BUILDLINK_PKGSRCDIR.tk85-itk?=	../../wip/tk85-itk

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../lang/tcl-itcl/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif	# TK85_ITK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk85-itk
