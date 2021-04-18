# $NetBSD$

DISTNAME=		gnunet-fuse-0.11.8
CATEGORIES=		filesystems
MASTER_SITES=		${MASTER_SITE_GNU:=gnunet/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gnunet.org/
COMMENT=		GNUnet FUSE extension
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS=		pkg-config
USE_LANGUAGES=		c

PTHREAD_OPTS=		require native
LDFLAGS+=		-lpthread

.include "../../wip/gnunet/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
