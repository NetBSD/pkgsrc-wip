# $NetBSD: buildlink3.mk,v 1.5 2010/01/04 13:32:29 obache Exp $

BUILDLINK_TREE+=	jbigkit

.if !defined(JBIGKIT_BUILDLINK3_MK)
JBIGKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jbigkit+=	jbigkit>=2.0
BUILDLINK_PKGSRCDIR.jbigkit?=	../../wip/jbigkit
.endif # JBIGKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-jbigkit
