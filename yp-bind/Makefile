# $NetBSD: Makefile,v 1.1.1.1 2003/12/06 00:20:17 jeremy-c-reed Exp $
#

DISTNAME=		ypbind-mt-1.12
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

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
