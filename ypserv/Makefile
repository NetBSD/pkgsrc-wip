# $NetBSD: Makefile,v 1.3 2004/01/27 23:38:01 jeremy-c-reed Exp $
#

DISTNAME=		ypserv-2.9
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.kernel.org/pub/linux/utils/net/NIS/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.linux-nis.org/nis/ypserv/
COMMENT=		NIS (YP) Server

DEPENDS+=		portmap>=4:../../wip/portmap
# rc.d scripts use domainname from yp-tools or net-tools
#DEPENDS+=		yp-tools-[0-9]*:../../wip/yp-tools

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

RCD_SCRIPTS=		yppasswdd ypserv

CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../databases/gdbm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
