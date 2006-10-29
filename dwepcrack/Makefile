# $NetBSD: Makefile,v 1.1.1.1 2006/10/29 13:19:22 gschwarz Exp $

DISTNAME=	dwepcrack-0.4
CATEGORIES=	security
MASTER_SITES=	http://www.unix-labs.org/pub/source/dwepcrack/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.dachb0den.com/projects/dwepcrack.html
COMMENT=	dwepcrack uses varioius methods to extract WEP keys

NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/dwepcrack ${PREFIX}/bin

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
