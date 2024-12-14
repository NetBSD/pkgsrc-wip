# $NetBSD: buildlink3.mk,v 1.102 2024/11/17 07:16:21 wiz Exp $

BUILDLINK_TREE+=	evolution-data-server

.if !defined(EVOLUTION_DATA_SERVER_BUILDLINK3_MK)
EVOLUTION_DATA_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server>=3.35.1
BUILDLINK_ABI_DEPENDS.evolution-data-server?=	evolution-data-server>=3.54.2
BUILDLINK_PKGSRCDIR.evolution-data-server?=	../../wip/evolution-data-server

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# EVOLUTION_DATA_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-evolution-data-server
