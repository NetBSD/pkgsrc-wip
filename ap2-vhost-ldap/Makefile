# $NetBSD: Makefile,v 1.2 2007/09/14 13:21:12 imilh Exp $

DISTNAME=	mod-vhost-ldap_1.2.0.orig
PKGNAME=	ap2-vhost-ldap-1.2.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/m/mod-vhost-ldap/}

MVL_VERSION=	${PKGNAME:S/ap2-vhost-ldap-//}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://packages.qa.debian.org/m/mod-vhost-ldap.html
COMMENT=	Apache 2.2 module LDAP Virtual Hosts support

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/:S/.orig//}
NO_CONFIGURE=	yes

APACHE_MODULE_NAME=	mod_vhost_ldap

do-build:
	cd ${WRKSRC} && \
	${APXS} -c -n ${APACHE_MODULE_NAME} \
	-I${BUILDLINK_PREFIX.openldap-client}/include \
	-L${BUILDLINK_PREFIX.openldap-client}/lib \
	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.-client}/lib \
	-DMOD_VHOST_LDAP_VERSION=\\\"mod_vhost_ldap/${MVL_VERSION}\\\" \
	-lldap_r mod_vhost_ldap.c

do-install:
	cd ${WRKSRC} && \
	${APXS} -i -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_NAME}.la

	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mod_vhost_ldap
	${INSTALL_DATA} ${WRKSRC}/vhost_ldap.conf \
		${PREFIX}/share/examples/mod_vhost_ldap
	${INSTALL_DATA} ${WRKSRC}/mod_vhost_ldap.schema \
		${PREFIX}/share/examples/mod_vhost_ldap

.include "../../www/apache22/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
