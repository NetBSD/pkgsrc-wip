# $NetBSD: Makefile,v 1.4 2006/10/29 11:23:09 shattered Exp $
#

DISTNAME=		sshfs-fuse-1.4
PKGNAME=		fuse-sshfs-1.4
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fuse/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://fuse.sourceforge.net/
COMMENT=		Mount remote directories using ssh and FUSE

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/fusefs/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
