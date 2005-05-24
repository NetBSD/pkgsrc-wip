# $NetBSD: Makefile,v 1.3 2005/05/24 10:31:41 rillig Exp $

DISTNAME=	sipsak-0.8.12
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
