# $NetBSD: Makefile,v 1.1.1.1 2005/04/09 15:34:45 gschwarz Exp $

DISTNAME=	sipsak-0.8.11
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/sipsak/

MAINTAINER=     schwarz@NetBSD.org
HOMEPAGE=	http://sipsak.org
COMMENT=	a command-line SIP testing utility

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

INSTALLATION_DIRS=	bin man/man1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
