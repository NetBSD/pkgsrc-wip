# $NetBSD$

BUILDLINK_TREE+=	cinnamon-settings-daemon

.if !defined(CINNAMON_SETTINGS_DAEMON_BUILDLINK3_MK)
CINNAMON_SETTINGS_DAEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cinnamon-settings-daemon+=	cinnamon-settings-daemon>=3.0.1
BUILDLINK_PKGSRCDIR.cinnamon-settings-daemon?=		../../wip/cinnamon-settings-daemon

.endif	# CINNAMON_SETTINGS_DAEMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-cinnamon-settings-daemon
