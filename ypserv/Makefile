# $NetBSD: Makefile,v 1.8 2008/03/09 03:20:08 tnn2 Exp $
#

DISTNAME=		ypserv-2.9
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.kernel.org/pub/linux/utils/net/NIS/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.linux-nis.org/nis/ypserv/
COMMENT=		NIS (YP) Server

DEPENDS+=		portmap>=4:../../net/portmap
# rc.d scripts use domainname from yp-tools or net-tools
#DEPENDS+=		yp-tools-[0-9]*:../../wip/yp-tools

GNU_CONFIGURE=		yes

RCD_SCRIPTS=		yppasswdd ypserv

CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
