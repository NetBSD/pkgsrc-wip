# $NetBSD$

BUILDLINK_TREE+=	tk-itk3

.if !defined(TK_ITK3_BUILDLINK3_MK)
TK_ITK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk-itk3+=	tk-itk3>=3.4.2
BUILDLINK_PKGSRCDIR.tk-itk3?=	../../wip/tk-itk3

.include "../../wip/tcl-itcl3/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif	# TK_ITK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk-itk3
