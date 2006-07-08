# $NetBSD: options.mk,v 1.1.1.1 2006/07/08 20:50:15 gschwarz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tacacs-shrubbery
PKG_SUPPORTED_OPTIONS=	acls-support drop-root-privileges
PKG_SUGGESTED_OPTIONS=	acls-support drop-root-privileges

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Macls-support)
CONFIGURE_ARGS+=	--enable-acls
.else
CONFIGURE_ARGS+=	--disable-acls
.endif

.if !empty(PKG_OPTIONS:Mdrop-root-privileges)
# tac_plus code requires numeric UID, GID
. if ${OPSYS} == "Linux"
TACACS_USER?=	65534 # nobody
TACACS_GROUP?=	65534
. else
TACACS_USER?=	-2 # nobody
TACACS_GROUP?=	-2
. endif
PKG_GROUPS=	${TACACS_GROUP}
PKG_USERS=	${TACACS_USER}:${TACACS_GROUP}
CONFIGURE_ARGS+=	--with-userid=${TACACS_USER:Q}
CONFIGURE_ARGS+=	--with-groupid=${TACACS_GROUP:Q}
.endif
