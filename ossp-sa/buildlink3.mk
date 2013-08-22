# $NetBSD: buildlink3.mk,v 1.1 2013/08/22 11:13:22 obache Exp $
#

BUILDLINK_TREE+=	ossp-sa

.if !defined(OSSP_SA_BUILDLINK3_MK)
OSSP_SA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ossp-sa+=	ossp-sa>=1.2.6
BUILDLINK_PKGSRCDIR.ossp-sa?=	../../wip/ossp-sa

#.include "../../wip/ossp-ex/buildlink3.mk"
.endif	# OSSP_SA_BUILDLINK3_MK

BUILDLINK_TREE+=	-ossp-sa
