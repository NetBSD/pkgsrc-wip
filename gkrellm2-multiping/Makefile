# $NetBSD: Makefile,v 1.1.1.1 2003/04/16 16:29:55 cubidou Exp $
#

DISTNAME=	gkrellm-multiping-2.0.2
CATEGORIES=	net
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/index.html
COMMENT=	pings several machines and prints out stats

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
SPECIAL_PERMS+=	${PREFIX}/lib/gkrellm2/plugins/pinger ${SETUID_ROOT_PERMS}

post-patch:
	${SED} -e s,@@PREFIX@@,${PREFIX}, ${WRKSRC}/multiping.c > ${WRKSRC}/multiping.c.sed
	${CP} ${WRKSRC}/multiping.c.sed ${WRKSRC}/multiping.c

.include "../../wip/gkrellm2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
