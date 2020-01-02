# $NetBSD$

DISTNAME=	ncrack-0.7
CATEGORIES=	security
MASTER_SITES=	https://nmap.org/ncrack/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nmap.org/ncrack/
COMMENT=	High-speed network authentication cracking tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE	# reallocarray(3)

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
