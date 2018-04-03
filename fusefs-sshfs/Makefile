# $NetBSD: Makefile,v 1.10 2012/11/25 23:32:13 othyro Exp $
#

DISTNAME=		sshfs-fuse-1.4
PKGNAME=		fuse-sshfs-1.4
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fuse/}
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fuse.sourceforge.net/
COMMENT=		Mount remote directories using ssh and FUSE

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../wip/bluez-libs/buildlink3.mk"
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
