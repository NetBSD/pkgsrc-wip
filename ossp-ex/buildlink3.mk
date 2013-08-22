# $NetBSD: buildlink3.mk,v 1.1 2013/08/22 11:11:45 obache Exp $
#

BUILDLINK_TREE+=	ossp-ex

.if !defined(OSSP_EX_BUILDLINK3_MK)
OSSP_EX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ossp-ex+=	ossp-ex>=1.0.6
BUILDLINK_PKGSRCDIR.ossp-ex?=	../../wip/ossp-ex
.endif	# OSSP_EX_BUILDLINK3_MK

BUILDLINK_TREE+=	-ossp-ex
