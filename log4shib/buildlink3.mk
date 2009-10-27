# $NetBSD: buildlink3.mk,v 1.1 2009/10/27 11:19:54 pettai Exp $
#

BUILDLINK_TREE+=	log4shib

.if !defined(LOG4SHIB_BUILDLINK3_MK)
LOG4SHIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.log4shib+=	log4shib>=1.0.3
BUILDLINK_PKGSRCDIR.log4shib?=	../../wip/log4shib
.endif	# LOG4SHIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-log4shib
