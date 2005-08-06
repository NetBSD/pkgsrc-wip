# $NetBSD: Makefile,v 1.13 2005/08/06 04:45:56 schnoebe Exp $

DISTNAME=		cvsd-1.0.8
CATEGORIES=		devel
MASTER_SITES=		http://ch.tudelft.nl/~arthur/cvsd/

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://ch.tudelft.nl/~arthur/cvsd/
COMMENT=		Run CVS pserver in a chroot-ed environment

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gmake perl
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-libwrap

RCD_SCRIPTS=		cvsd

EGDIR=			${PREFIX}/share/examples/cvsd
CONF_FILES=		${EGDIR}/cvsd.conf.example ${PKG_SYSCONFDIR}/cvsd.conf

CVSD_USER?=		cvsd
CVSD_GROUP?=		cvsd
PKG_USERS=		${CVSD_USER}:${CVSD_GROUP}::CVS\\ wrapper:
PKG_GROUPS=		${CVSD_GROUP}

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
