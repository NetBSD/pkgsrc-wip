# $NetBSD: Makefile,v 1.4 2005/07/03 19:39:37 gschwarz Exp $

DISTNAME=	sipsak-0.8.13
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/sipsak/

MAINTAINER=     schwarz@NetBSD.org
HOMEPAGE=	http://sipsak.org
COMMENT=	a command-line SIP testing utility

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin man/man1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
