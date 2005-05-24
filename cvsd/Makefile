# $NetBSD: Makefile,v 1.12 2005/05/24 10:29:26 rillig Exp $

DISTNAME=		cvsd-1.0.3
CATEGORIES=		devel
MASTER_SITES=		http://tiefighter.et.tudelft.nl/~arthur/cvsd/

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://tiefighter.et.tudelft.nl/~arthur/cvsd/
COMMENT=		Run CVS pserver in a chroot-ed environment

.include "../../mk/bsd.prefs.mk"

USE_PERL5=		YES
USE_TOOLS+=		gmake
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
