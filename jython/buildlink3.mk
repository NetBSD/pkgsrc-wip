# $NetBSD: buildlink3.mk,v 1.1 2010/08/24 13:12:37 jihbed Exp $

BUILDLINK_TREE+=	jython

.if !defined(JYTHON_BUILDLINK3_MK)
JYTHON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jython+=	jython>=2.5.2b1
BUILDLINK_PKGSRCDIR.jython?=	../../wip/jython
.endif	# JYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-jython
