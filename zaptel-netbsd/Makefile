# $NetBSD: Makefile,v 1.4 2005/03/21 06:35:44 riz Exp $
#

DISTNAME=		zaptel-netbsd-20050320
CATEGORIES=		wip
MASTER_SITES=		http://www.tastylime.net/netbsd/zaptel/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		riz@NetBSD.org
HOMEPAGE=		http://www.tastylime.net/netbsd/zaptel/
COMMENT=		zaptel drivers for the Asterisk Software PBX

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-*
INSTALLATION_DIRS=	lkm

ZAPTEL_KERNEL_ENV?=	# empty
BUILD_DEFS+=		ZAPTEL_KERNEL_ENV
MAKE_ENV+=		ZAPTEL_KERNEL_ENV=${ZAPTEL_KERNEL_ENV:Q}
CONF_FILES=		${PREFIX}/share/examples/zaptel/zaptel.conf \
			${PKG_SYSCONFDIR}/zaptel.conf

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
RCD_SCRIPTS=		ztcfg

.include "../../wip/newt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
