# $NetBSD: buildlink3.mk,v 1.1 2013/08/22 11:12:34 obache Exp $
#

BUILDLINK_TREE+=	ossp-l2

.if !defined(OSSP_L2_BUILDLINK3_MK)
OSSP_L2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ossp-l2+=	ossp-l2>=0.9.13
BUILDLINK_PKGSRCDIR.ossp-l2?=	../../wip/ossp-l2

.endif	# OSSP_L2_BUILDLINK3_MK

BUILDLINK_TREE+=	-ossp-l2
