# $NetBSD: Makefile,v 1.4 2005/04/11 21:16:37 tvierling Exp $
#

DISTNAME=		ypbind-mt-1.12
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.kernel.org/pub/linux/utils/net/NIS/ \
			http://www.us.kernel.org/pub/linux/utils/net/NIS/ \
			ftp://ftp.kr.kernel.org/pub/linux/utils/net/NIS/ \
			http://www.de.kernel.org/pub/linux/utils/net/NIS/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.linux-nis.org/nis/ypbind-mt/
COMMENT=		Multithreaded NIS (YP) client daemon

DEPENDS+=		portmap>=4:../../wip/portmap
# rc.d script uses domainname from yp-tools or net-tools
#DEPENDS+=		yp-tools-[0-9]*:../../wip/yp-tools

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
RCD_SCRIPTS=		ypbind

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
