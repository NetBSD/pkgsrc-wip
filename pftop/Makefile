# $NetBSD: Makefile,v 1.5 2004/10/26 22:42:56 ppostma Exp $

DISTNAME=	pftop-0.4
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/

MAINTAINER=	peter@pointless.nl
HOMEPAGE=	http://www.eee.metu.edu.tr/~canacar/pftop/
COMMENT=	Utility for real-time display of statistics for PF

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes

MAKE_ENV+=	OSLEVEL=${_PF_VERSION:S/.//}
CFLAGS+=	-I${PREFIX}/include

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 ${PREFIX}/man/man8

.include "../../wip/pflkm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
