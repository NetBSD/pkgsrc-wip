# $NetBSD: options.mk,v 1.1 2007/12/02 21:19:23 ondratu Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.hal
PKG_SUPPORTED_OPTIONS=	policykit
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpolicykit)
.include "../../wip/policykit/buildlink3.mk"

CONFIGURE_ARGS+=	--enable-policy-kit

POLICYKIT_DIR=		${PKG_SYSCONFDIR}/PolicyKit/privilege.d

CONF_FILES+=		${EGDIR}/hal-power-cpufreq.privilege ${POLICYKIT_DIR}/hal-power-cpufreq.privilege
CONF_FILES+=		${EGDIR}/hal-power-hibernate.privilege ${POLICYKIT_DIR}/hal-power-hibernate.privilege
CONF_FILES+=		${EGDIR}/hal-power-poweroff.privilege ${POLICYKIT_DIR}/hal-power-poweroff.privilege
CONF_FILES+=		${EGDIR}/hal-power-reboot.privilege ${POLICYKIT_DIR}/hal-power-reboot.privilege
CONF_FILES+=		${EGDIR}/hal-power-suspend.privilege ${POLICYKIT_DIR}/hal-power-suspend.privilege
CONF_FILES+=		${EGDIR}/hal-storage-fixed-mount-all-options.privilege ${POLICYKIT_DIR}/hal-storage-fixed-mount-all-options.privilege
CONF_FILES+=		${EGDIR}/hal-storage-fixed-mount.privilege ${POLICYKIT_DIR}/hal-storage-fixed-mount.privilege
CONF_FILES+=		${EGDIR}/hal-storage-removable-mount-all-options.privilege ${POLICYKIT_DIR}/hal-storage-removable-mount-all-options.privilege
CONF_FILES+=		${EGDIR}/hal-storage-removable-mount.privilege ${POLICYKIT_DIR}/hal-storage-removable-mount.privilege

.endif
