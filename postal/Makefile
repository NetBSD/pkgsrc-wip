# $NetBSD: Makefile,v 1.1.1.1 2003/09/02 05:53:56 xtraeme Exp $

DISTNAME=	postal-0.61
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/postal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@netbsd-fr.org
COMMENT=	Tool for benchmarking SMTP/POP servers

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

post-patch:
	@cd ${WRKSRC}; ${AUTOCONF}

.include "../../devel/pth/buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
