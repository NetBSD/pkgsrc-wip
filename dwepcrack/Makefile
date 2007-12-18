# $NetBSD: Makefile,v 1.2 2007/12/18 18:54:53 shattered Exp $

DISTNAME=	dwepcrack-0.4
CATEGORIES=	security
MASTER_SITES=	http://www.unix-labs.org/pub/source/dwepcrack/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20070322102507/http://www.dachb0den.com/projects/dwepcrack.html
COMMENT=	dwepcrack uses varioius methods to extract WEP keys

NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/dwepcrack ${PREFIX}/bin

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
