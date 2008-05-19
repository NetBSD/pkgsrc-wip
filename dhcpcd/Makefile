# $NetBSD: Makefile,v 1.7 2008/05/19 13:50:58 rsmarples Exp $
#

DISTNAME=		dhcpcd-4.0.0-beta4
PKGNAME=		dhcpcd-4.0.0beta4
CATEGORIES=		net
MASTER_SITES=		http://roy.marples.name/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@marples.name
HOMEPAGE=		http://roy.marples.name/dhcpcd/
COMMENT=		RFC2131 compliant DHCP client

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99

EGDIR=			${PREFIX}/share/examples/dhcpcd
SYSDIR=			${PKG_SYSCONFDIR}/dhcpcd
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

# Install the main configuration file and script
OWN_DIRS+=		${SYSDIR}
CONF_FILES_PERMS+=	${EGDIR}/dhcpcd.sh ${SYSDIR}/dhcpcd.sh \
			${ROOT_USER} ${ROOT_GROUP} 0755
CONF_FILES+=		${EGDIR}/dhcpcd.conf ${SYSDIR}/dhcpcd.conf

# The RC script needs some loving
RCD_SCRIPTS+=		dhcpcd

# Install the ntp.sh hook script by default
OWN_DIRS+=		${SYSDIR}/dhcpcd-exit-hook.d
CONF_FILES+=		${EGDIR}/dhcpcd-exit-hook.d/ntp.sh \
			${SYSDIR}/dhcpcd-exit-hook.d/ntp.sh
post-install:
	${INSTALL_DATA_DIR} ${EGDIR}/dhcpcd-exit-hook.d
	${INSTALL_DATA} ${WRKSRC}/hook-samples/ntp.sh \
		${EGDIR}/dhcpcd-exit-hook.d

.include "../../mk/bsd.pkg.mk"
