# $NetBSD: Makefile,v 1.5 2013/01/03 12:08:07 othyro Exp $
#

DISTNAME=	thcrut-1.2.5
CATEGORIES=	net
MASTER_SITES=	http://www.thc.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.thc.org/thc-rut/
COMMENT=	Gathers information from local and remote networks
#LICENSE=	# XXX See ${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf autoheader automake makeinfo

.include "../../devel/libnet10/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
