# $NetBSD: Makefile,v 1.2 2003/10/25 06:48:06 xtraeme Exp $

DISTNAME=	postal-0.62
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/postal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.coker.com.au/postal/
COMMENT=	Tool for benchmarking SMTP/POP servers

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
