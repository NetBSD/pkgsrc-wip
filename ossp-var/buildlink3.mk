# $NetBSD: buildlink3.mk,v 1.1 2013/08/22 11:14:58 obache Exp $
#

BUILDLINK_TREE+=	ossp-var

.if !defined(OSSP_VAR_BUILDLINK3_MK)
OSSP_VAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ossp-var+=	ossp-var>=1.1.3
BUILDLINK_PKGSRCDIR.ossp-var?=	../../wip/ossp-var

#.include "../../wip/ossp-ex/buildlink3.mk"
.endif	# OSSP_VAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ossp-var
