# $NetBSD: buildlink3.mk,v 1.1 2014/02/14 21:03:03 nros Exp $
#

BUILDLINK_TREE+=	qore-opengl-module

.if !defined(QORE_OPENGL_MODULE_BUILDLINK3_MK)
QORE_OPENGL_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-opengl-module+=	qore-opengl-module>=0.0.3
BUILDLINK_PKGSRCDIR.qore-opengl-module?=	../../wip/qore-opengl-module

.include "../../wip/qore/buildlink3.mk"
.endif	# QORE_OPENGL_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-opengl-module
