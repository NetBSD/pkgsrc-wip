# $NetBSD: Makefile,v 1.8 2012/10/03 18:15:32 asau Exp $
#

DISTNAME=	netwib-5.35.0-src
PKGNAME=	netwib-5.35.0
CATEGORIES=	security net
MASTER_SITES=	http://www.laurentconstantin.com/common/netw/netwib/download/v5/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://www.laurentconstantin.com/en/netw/
COMMENT=	Network library providing network functionality for developers


WRKSRC=			${WRKDIR}/${DISTNAME}/src
HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./genemake
ONLY_FOR_PLATFORM=	NetBSD-*-i386

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		config.dat
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths=		-e 's,/man$$,/${PKGMANDIR},g'


.include "../../devel/libnet10/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
