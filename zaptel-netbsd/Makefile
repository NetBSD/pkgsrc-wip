# $NetBSD: Makefile,v 1.2 2005/03/16 20:05:31 riz Exp $
#

DISTNAME=		zaptel-netbsd-20050314
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

.include "../../wip/newt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
