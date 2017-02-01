# $NetBSD$

DISTNAME=	john-1.8.0-jumbo-1
CATEGORIES=	wip
MASTER_SITES=	http://openwall.com/john/j/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://openwall.com/john/
COMMENT=	Unix Password Cracker (community-enhanced version)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	src

USE_TOOLS+=	gmake

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
