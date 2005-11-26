# $NetBSD: Makefile,v 1.7 2005/11/26 19:18:16 gschwarz Exp $

DISTNAME=	sipsak-0.9.5
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/sipsak/

MAINTAINER=     schwarz@NetBSD.org
HOMEPAGE=	http://sipsak.org/
COMMENT=	Sipsak is a command-line SIP testing utility

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
