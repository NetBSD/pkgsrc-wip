# $NetBSD: Makefile,v 1.2 2004/06/09 21:41:50 adrian_p Exp $
#

DISTNAME=	netwib-5.16.0-src
PKGNAME=	netwib-5.16.0
CATEGORIES=	security net
MASTER_SITES=	http://www.laurentconstantin.com/common/netw/netwib/download/v5/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://www.laurentconstantin.com/en/netw/
COMMENT=	Network library providing network functionality for developers

WRKSRC=         	${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=		YES
HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./genemake
ONLY_FOR_PLATFORM=      NetBSD-*-i386

post-patch:
	@${CP} ${WRKSRC}/config.dat ${WRKSRC}/config.dat.new
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' \
		< ${WRKSRC}/config.dat.new > ${WRKSRC}/config.dat

.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
