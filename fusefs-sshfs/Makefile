# $NetBSD: Makefile,v 1.1.1.1 2006/02/12 03:04:43 poppnk Exp $
#

DISTNAME=		sshfs-fuse-1.4
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fuse/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://nchc.dl.sourceforge.net/sourceforge/fuse/
COMMENT=		Mount remote directories using ssh and FUSE
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/fusefs/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
