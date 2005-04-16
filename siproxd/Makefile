# $NetBSD: Makefile,v 1.1.1.1 2005/04/16 22:53:42 gschwarz Exp $

DISTNAME=	siproxd-16Apr2005
CATEGORIES=	net
MASTER_SITES=	http://home.tiscalinet.ch/ries/siproxd/

MAINTAINER=     schwarz@NetBSD.org
HOMEPAGE=	http://siproxd.sourceforge.net/
COMMENT=	a SIP ALG

WRKSRC=		${WRKDIR}/siproxd-0.5.11
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-libosip-prefix=${BUILDLINK_PREFIX.libosip2}

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:S|^${PREFIX}/||}

INSTALLATION_DIRS=	sbin ${PKG_SYSCONFDIR:S|^${PREFIX}/||}

.include "../../devel/libosip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
