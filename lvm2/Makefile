# $NetBSD: Makefile,v 1.1 2016/07/08 09:09:47 kamil Exp $

DISTNAME=	LVM2.2.03.14
PKGNAME=	${DISTNAME:S/LVM2./lvm2-/}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://sourceware.org/pub/lvm2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sourceware.org/lvm2/
COMMENT=	Linux userspace toolset for volume management facilities
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake bash

ONLY_FOR_PLATFORM=	Linux-*-*

MAKE_FLAGS+=	SHELL=${TOOLS_PLATFORM.bash}

PKGCONFIG_OVERRIDE+=	daemons/dmeventd/libdevmapper-event.pc.in
PKGCONFIG_OVERRIDE+=	libdm/libdevmapper.pc.in
PKGCONFIG_OVERRIDE+=	liblvm/liblvm2app.pc.in

.include "../../wip/libaio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
