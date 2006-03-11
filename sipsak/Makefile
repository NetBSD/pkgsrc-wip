# $NetBSD: Makefile,v 1.8 2006/03/11 18:09:09 gschwarz Exp $

DISTNAME=	sipsak-0.9.6-1
PKGNAME=	${DISTNAME:S/-1//}
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/sipsak/

MAINTAINER=     schwarz@NetBSD.org
HOMEPAGE=	http://sipsak.org/
COMMENT=	Sipsak is a command-line SIP testing utility

WRKSRC=		${WRKDIR}/${DISTNAME:S/-1//}

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
