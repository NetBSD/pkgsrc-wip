# $NetBSD: Makefile,v 1.8 2005/04/04 15:17:00 riz Exp $
#

DISTNAME=		zaptel-netbsd-20050404
CATEGORIES=		wip
MASTER_SITES=		http://www.tastylime.net/netbsd/zaptel/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	http://www.tastylime.net/netbsd/zaptel/
COMMENT=	The "zaptel" drivers and utils for the Asterisk Software PBX

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-*
INSTALLATION_DIRS=	lkm

ZAPTEL_KERNEL_ENV?=	# empty
BUILD_DEFS+=		ZAPTEL_KERNEL_ENV
MAKE_ENV+=		ZAPTEL_KERNEL_ENV=${ZAPTEL_KERNEL_ENV:Q}
CONF_FILES=		${PREFIX}/share/examples/zaptel/zaptel.conf \
			${PKG_SYSCONFDIR}/zaptel.conf

USE_PKGINSTALL=		yes
RCD_SCRIPTS=		ztcfg

.include "../../wip/newt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
