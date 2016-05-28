# $Id: Makefile,v 1.4 2012/09/28 21:24:33 asau Exp $

DISTNAME=		# empty
DISTFILES=		${DEBS}
PKGNAME=		debian_x11-3.0.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/x/xfree86/} \
			http://security.debian.org/debian-security/pool/updates/main/x/xfree86/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.debian.org/
COMMENT=		Debian Linux X11 compatibility libraries

DEPENDS+=		debian_base-[0-9]*:../../wip/debian_base

DIST_SUBDIR=		debian_linux

DEBS=			xlibs_4.3.0.dfsg.1-4_all.deb
DEBS+=			libxi6_4.3.0.dfsg.1-4_${MACHINE_ARCH}.deb
DEBS+=			libice6_4.3.0.dfsg.1-4_${MACHINE_ARCH}.deb
DEBS+=			libsm6_4.3.0.dfsg.1-4_${MACHINE_ARCH}.deb
DEBS+=			libx11-6_4.3.0.dfsg.1-4_${MACHINE_ARCH}.deb
DEBS+=			libxext6_4.3.0.dfsg.1-4_${MACHINE_ARCH}.deb
DEBS+=			libxmu6_4.3.0.dfsg.1-4_${MACHINE_ARCH}.deb
DEBS+=			libxmuu1_4.3.0.dfsg.1-4_${MACHINE_ARCH}.deb
DEBS+=			libxp6_4.3.0.dfsg.1-4_${MACHINE_ARCH}.deb
DEBS+=			libxpm4_4.3.0.dfsg.1-4_${MACHINE_ARCH}.deb
DEBS+=			libxt6_4.3.0.dfsg.1-4_${MACHINE_ARCH}.deb
DEBS+=			xlibs-data_4.3.0.dfsg.1-4_all.deb


do-extract:		do-extract-deb
do-install:		do-install-deb

.include "../../wip/debian_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
