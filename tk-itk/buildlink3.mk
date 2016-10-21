# $NetBSD: buildlink3.mk,v 1.4 2013/01/07 13:30:24 thomasklausner Exp $

BUILDLINK_TREE+=	tk-itk

.if !defined(TK_ITK_BUILDLINK3_MK)
TK_ITK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk-itk+=	tk-itk>=3.3
BUILDLINK_PKGSRCDIR.tk-itk?=	../../wip/tk-itk

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../lang/tcl-itcl/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif	# TK_ITK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk-itk
