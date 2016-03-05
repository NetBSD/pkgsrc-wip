# $NetBSD$

BUILDLINK_TREE+=	evolution-data-server

.if !defined(EVOLUTION_DATA_SERVER_BUILDLINK3_MK)
EVOLUTION_DATA_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server>=3.18.4
BUILDLINK_PKGSRCDIR.evolution-data-server?=	../../wip/evolution-data-server

.include "../../wip/libgweather/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.endif	# EVOLUTION_DATA_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-evolution-data-server
