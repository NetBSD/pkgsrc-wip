# $NetBSD: Makefile,v 1.6 2005/11/05 18:28:51 gschwarz Exp $

DISTNAME=	sipsak-0.9.2
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/sipsak/

MAINTAINER=     schwarz@NetBSD.org
HOMEPAGE=	http://sipsak.org
COMMENT=	Sipsak is a command-line SIP testing utility

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
