# $NetBSD: buildlink3.mk,v 1.3 2012/01/22 12:25:52 mwdavies Exp $

BUILDLINK_TREE+=	redland

.if !defined(REDLAND_BUILDLINK3_MK)
REDLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.redland+=	redland>=1.0.7
BUILDLINK_ABI_DEPENDS.redland?=	redland>=1.0.12nb2
BUILDLINK_PKGSRCDIR.redland?=	../../wip/redland

.include "../../security/openssl/buildlink3.mk"
.include "../../wip/raptor2/buildlink3.mk"
.include "../../wip/rasqal/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.endif # REDLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-redland
