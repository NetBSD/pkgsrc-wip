# $NetBSD: Makefile,v 1.2 2003/12/06 08:46:33 jeremy-c-reed Exp $
#

DISTNAME=		ypserv-2.9
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.kernel.org/pub/linux/utils/net/NIS/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.linux-nis.org/nis/ypserv/
COMMENT=		NIS (YP) Server

DEPENDS+=		portmap>=4:../../wip/portmap

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../databases/gdbm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
