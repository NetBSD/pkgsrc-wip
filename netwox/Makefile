# $NetBSD: Makefile,v 1.1.1.1 2004/05/19 02:36:29 adrian_p Exp $
#

DISTNAME=	netwox-5.16.0-src
PKGNAME=	netwox-5.16.0
CATEGORIES=	security net
MASTER_SITES=	http://www.laurentconstantin.com/common/netw/netwox/download/v5/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://www.laurentconstantin.com/en/netw/
COMMENT=	Toolbox that helps to find and solve network problems

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
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/netwib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
