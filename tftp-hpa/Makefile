# $NetBSD: Makefile,v 1.2 2007/07/16 18:03:26 gschwarz Exp $

DISTNAME=	tftp-hpa-0.48
CATEGORIES=	net
MASTER_SITES=	http://www.kernel.org/pub/software/network/tftp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://freshmeat.net/projects/tftp-hpa/
COMMENT=	Enhanced version of the BSD TFTP client and server

GNU_CONFIGURE=	YES
USE_TOOLS+=	autoconf gmake

.include 	"options.mk"

INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
