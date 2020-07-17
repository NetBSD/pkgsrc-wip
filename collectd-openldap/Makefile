# $NetBSD: Makefile,v $

COLLECTD_PACKAGE=	openldap

COMMENT=		Statistics collection daemon - openldap plugin

.include "../../databases/openldap-client/buildlink3.mk"
COLLECTD_LIB.ldap=	${BUILDLINK_PREFIX.openldap-client}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
