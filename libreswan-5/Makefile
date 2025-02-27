# $NetBSD$

# Libreswan is built using GNU Make.  It does not use autoconf.
#
# Configuration parameters can be found in mk/config.mk and OS
# specific overides in mk/default/*.mk (for instance,
# mk/default/netbsd.mk).

# See:
#    pkg_admin pmatch 'foo>=5.0rc1' foo-5.0pre0.20230807
# the suggestion is:
#
# libreswan-git: 5.0pre0.YYYYMMDD 5.0rc1 5.0rc1.YYYYMMDD 5.0
# 5.1pre.YYYYMMDD ...
#
# libreswan: 5.0 5.0nb1 ...

DISTNAME=	libreswan-5.2
MASTER_SITES=   https://download.libreswan.org/

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

EGDIR=		${PREFIX}/share/examples/libreswan

# Config files: stop libreswan 4.10+ scribbling into /etc
MAKE_FLAGS+=	INSTALL_CONFIGS=false

# Init scripts aka rc.d: stop libreswan 4.10+ scribbing into /etc
MAKE_FLAGS+=	INSTALL_INITSYSTEM=false
FILESDIR=	${DESTDIR}${EGDIR}/rc.d
post-install:
	mv $(FILESDIR)/pluto $(FILESDIR)/pluto.sh
#RCD_SCRIPTS=	pluto
#CONF_FILES+=	${EGDIR}/rc.d/ipsec ${PKG_SYSCONFDIR}/rc.d/ipsec

# populate /etc
PERMS=$(REAL_ROOT_USER) $(REAL_ROOT_GROUP) 0700
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/ipsec.d $(PERMS)
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/ipsec.d/policies $(PERMS)
CONF_FILES_PERMS+=	${EGDIR}/ipsec.secrets-sample ${PKG_SYSCONFDIR}/ipsec.secrets $(PERMS)
CONF_FILES_PERMS+=	${EGDIR}/ipsec.conf-sample ${PKG_SYSCONFDIR}/ipsec.conf $(PERMS)
CONF_FILES+=		${EGDIR}/ipsec.d/policies/portexcludes.conf ${PKG_SYSCONFDIR}/ipsec.d/policies/portexcludes.conf
# needs a for loop
CONF_FILES+=		${EGDIR}/ipsec.d/policies/block ${PKG_SYSCONFDIR}/ipsec.d/policies/block
CONF_FILES+=		${EGDIR}/ipsec.d/policies/clear ${PKG_SYSCONFDIR}/ipsec.d/policies/clear
CONF_FILES+=		${EGDIR}/ipsec.d/policies/clear-or-private ${PKG_SYSCONFDIR}/ipsec.d/policies/clear-or-private
CONF_FILES+=		${EGDIR}/ipsec.d/policies/private ${PKG_SYSCONFDIR}/ipsec.d/policies/private
CONF_FILES+=		${EGDIR}/ipsec.d/policies/private-or-clear ${PKG_SYSCONFDIR}/ipsec.d/policies/private-or-clear

# Always install pam.d!?
MAKE_DIRS+=	${PKG_SYSCONFDIR}/pam.d
CONF_FILES+=	${EGDIR}/pam.d/pluto ${PKG_SYSCONFDIR}/pam.d/pluto

# Alway install logrotate!?!
MAKE_DIRS+=	${PKG_SYSCONFDIR}/logrotate.d
CONF_FILES+=	${EGDIR}/logrotate.d/libreswan ${PKG_SYSCONFDIR}/logrotate.d/libreswan

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
