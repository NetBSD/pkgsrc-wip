# $NetBSD: Makefile,v 1.5 2009/04/19 20:20:10 gschwarz Exp $

DISTNAME=	dwepcrack-0.4
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.e.kth.se/~pvz/wifi/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20070322102507/http://www.dachb0den.com/projects/dwepcrack.html
COMMENT=	Dwepcrack uses varioius methods to extract WEP keys

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/dwepcrack ${DESTDIR}${PREFIX}/bin

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
