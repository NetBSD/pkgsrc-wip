# $NetBSD: buildlink3.mk,v 1.1 2014/01/20 19:23:27 nros Exp $
#

BUILDLINK_TREE+=	qore-yaml-module

.if !defined(QORE_YAML_MODULE_BUILDLINK3_MK)
QORE_YAML_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-yaml-module+=	qore-yaml-module>=0.4
BUILDLINK_PKGSRCDIR.qore-yaml-module?=	../../wip/qore-yaml-module


.include "../../wip/qore/buildlink3.mk"
.endif	# QORE_YAML_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-yaml-module
