# $NetBSD: Makefile,v 1.4 2003/12/31 10:52:15 cubidou Exp $
#

DISTNAME=	gkrellm-multiping-2.0.6
CATEGORIES=	net
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/index.html
COMMENT=	Pings several machines and prints out stats

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
SPECIAL_PERMS+=	${PREFIX}/lib/gkrellm2/plugins/pinger ${SETUID_ROOT_PERMS}

post-patch:
	${SED} -e s,@@PREFIX@@,${PREFIX}, ${WRKSRC}/multiping.c > ${WRKSRC}/multiping.c.sed
	${CP} ${WRKSRC}/multiping.c.sed ${WRKSRC}/multiping.c

.include "../../wip/gkrellm2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
