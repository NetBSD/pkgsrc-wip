# $NetBSD: Makefile,v 1.3 2003/08/29 10:31:25 thomasklausner Exp $

# XXX This version was based on number of cvs revisions.
DISTNAME=		rcorder-0.11
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Print a dependency ordering of interdependent files

# NetBSD since 1.5.2? has this included in base install.
NOT_FOR_PLATFORM=	NetBSD-*-*

NO_CHECKSUM=		# defined

USE_BUILDLINK2=		# defined

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../pkgtools/libnbcompat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
