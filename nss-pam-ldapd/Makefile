# $NetBSD: Makefile,v 1.1 2012/12/11 20:21:43 ftigeot Exp $

DISTNAME=	nss-pam-ldapd-0.8.12
CATEGORIES=	databases
MASTER_SITES=	http://arthurdejong.org/nss-pam-ldapd/

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://arthurdejong.org/nss-pam-ldapd/
COMMENT=	LDAP client for nsswitch
LICENSE=	gnu-lgpl-v2

PKG_USERS=		nslcd:nslcd
PKG_GROUPS=		nslcd

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${EGDIR}/nslcd.conf

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/nslcd.conf
CONF_FILES+=		${PKG_SYSCONFDIR}/nslcd.conf

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
