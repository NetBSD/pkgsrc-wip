# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:33 asau Exp $

DISTNAME=		# empty
DISTFILES=		${DEBS}
PKGNAME=		debian_gtk-1.2.10.16
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/g/gtk+1.2/}

COMMENT=		Debian Linux gtk1.2 package

DEPENDS+=		debian_glib>=1.2:../../wip/debian_glib
DEPENDS+=		debian_x11-[0-9]*:../../wip/debian_x11

DEBS=			libgtk1.2_1.2.10-16_${MACHINE_ARCH}.deb
DEBS=			libgtk1.2-common_1.2.10-16_all.deb


do-extract:		do-extract-deb
do-install:		do-install-deb

.include "../../wip/debian_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
