# $NetBSD$

# Libreswan is built using GNU Make (it does not use autoconf).
#
# Configuration parameters can be found in mk/config.mk and OS
# specific overides in mk/default/*.mk (for instance,
# mk/default/netbsd.mk).

DISTNAME=	libreswan-4.15
PKGREVISION=	0
MASTER_SITES=	https://download.libreswan.org/

CATEGORIES=	security
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libreswan.org/
# Libreswan is an ...
COMMENT=	Internet Key Exchange Daemon for managing IPsec
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_TOOLS+=	flex
USE_TOOLS+=	bison
#default is: USE_LANGUAGES+=	c

# 4.x installs config files and the rc.d script into /etc and not
# examples/. Hence, need to move them to their proper directory.
# 5.x should have this fixed.

EGDIR=		${PREFIX}/share/examples
MAKE_FLAGS=
MAKE_FLAGS+=	FINALDOCDIR=${EGDIR}/libreswan/
MAKE_FLAGS+=	FINALCONFDDIR=${EGDIR}/libreswan/ipsec.d
post-install:
	rm -f ${DESTDIR}/usr/pkg/etc/ipsec.conf
	rm -f ${DESTDIR}/usr/pkg/etc/ipsec.secrets
	rm -f ${DESTDIR}/usr/pkg/etc/rc.d/pluto
	mv ${DESTDIR}${EGDIR}/rc.d/pluto ${DESTDIR}${EGDIR}/rc.d/ipsec
	mv ${DESTDIR}/etc/pam.d ${DESTDIR}${EGDIR}/pam.d
	mv ${DESTDIR}/usr/pkg/etc/logrotate.d ${DESTDIR}${EGDIR}/logrotate.d
#RCD_SCRIPTS=	pluto
CONF_FILES+=		${EGDIR}/rc.d/ipsec					${PKG_SYSCONFDIR}/rc.d/ipsec

# populate /etc
PERMS=$(REAL_ROOT_USER) $(REAL_ROOT_GROUP) 0700
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/ipsec.d $(PERMS)
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/ipsec.d/policies $(PERMS)
CONF_FILES_PERMS+=	${EGDIR}/libreswan/ipsec.secrets-sample			${PKG_SYSCONFDIR}/ipsec.secrets $(PERMS)
CONF_FILES_PERMS+=	${EGDIR}/libreswan/ipsec.conf-sample			${PKG_SYSCONFDIR}/ipsec.conf $(PERMS)
CONF_FILES+=		${EGDIR}/libreswan/ipsec.d/policies/portexcludes.conf	${PKG_SYSCONFDIR}/ipsec.d/policies/portexcludes.conf
# needs a for loop
CONF_FILES+=		${EGDIR}/libreswan/ipsec.d/policies/block		${PKG_SYSCONFDIR}/ipsec.d/policies/block
CONF_FILES+=		${EGDIR}/libreswan/ipsec.d/policies/clear		${PKG_SYSCONFDIR}/ipsec.d/policies/clear
CONF_FILES+=		${EGDIR}/libreswan/ipsec.d/policies/clear-or-private	${PKG_SYSCONFDIR}/ipsec.d/policies/clear-or-private
CONF_FILES+=		${EGDIR}/libreswan/ipsec.d/policies/private		${PKG_SYSCONFDIR}/ipsec.d/policies/private
CONF_FILES+=		${EGDIR}/libreswan/ipsec.d/policies/private-or-clear 	${PKG_SYSCONFDIR}/ipsec.d/policies/private-or-clear

# Always install pam.d!?
MAKE_DIRS+=		${PKG_SYSCONFDIR}/pam.d
CONF_FILES+=		${EGDIR}/pam.d/pluto					${PKG_SYSCONFDIR}/pam.d/pluto

# Alway install logrotate!?!
MAKE_DIRS+=		${PKG_SYSCONFDIR}/logrotate.d
CONF_FILES+=		${EGDIR}/logrotate.d/libreswan ${PKG_SYSCONFDIR}/logrotate.d/libreswan

CHECK_PORTABILITY_SKIP=	mk/docker-targets.mk

# code not clean enough; XXX: why?
#BUILDLINK_TRANSFORM+=	rm:-Werror

# some stuff uses .include, some does not
DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

# libevent?
.include "../../net/unbound/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
