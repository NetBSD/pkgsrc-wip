# $Id: Makefile,v 1.4 2012/09/28 21:24:33 asau Exp $

DISTNAME=		# empty
DISTFILES=		${DEBS}
PKGNAME=		debian_glib-1.2.10.9
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/g/glib1.2/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.debian.org/
COMMENT=		Debian Linux glib1.2 package

ONLY_FOR_PLATFORM+=	NetBSD-1.6*-i386
ONLY_FOR_PLATFORM+=	NetBSD-[2-9]*-i386

DEPENDS+=		debian_base-[0-9]*:../../wip/debian_base

DIST_SUBDIR=		debian_linux

DEBS=			libglib1.2_1.2.10-9_${MACHINE_ARCH}.deb


do-extract:		do-extract-deb
do-install:		do-install-deb

.include "../../wip/debian_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
