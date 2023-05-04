# $NetBSD$

# Libreswan is built using GNU Make.  It does not use autoconf.
#
# Configuration parameters can be found in mk/config.mk and OS
# specific overides in mk/default/*.mk (for instance,
# mk/default/netbsd.mk).

#DISTNAME=	libreswan-4.9
#MASTER_SITES=	https://download.libreswan.org/

GITHUB_PROJECT=	libreswan
DISTNAME=	libreswan

# This is a pre-5.0 snapshot taken from mainline.  It includes the CVE
# fixes in v4.10 and v4.11.
#
# The version number 4.9 in the below is topologically correct.  It is
# the point where the v4.x maintenance branch was created (both v4.10
# and v4.11 were drawn from that branch).
#
# If this were Fedora I'd be using something like libreswan-v4.9~1324
# (that's a tilda).  Perhaps 4.11nb5.1324 would be better?

PKGNAME=	libreswan-4.9nb3
GITHUB_TAG=	87b84cc19b90a4e046f28568cc2738835800398a
MASTER_SITES=	${MASTER_SITE_GITHUB:=${GITHUB_PROJECT}/}
DIST_SUBDIR=	${GITHUB_PROJECT}

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
