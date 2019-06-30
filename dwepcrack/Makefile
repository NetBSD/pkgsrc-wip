# $NetBSD: Makefile,v 1.9 2013/12/12 11:37:14 gschwarz Exp $

DISTNAME=	dwepcrack-0.4
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://index-of.es/Hacking-Wireless-Networks/WEP-WPA%20Cracking%20Tools/dwepcrack/
MASTER_SITES+=	http://www.hacker-soft.net/tools/Assessment/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20070322102507/http://www.dachb0den.com/projects/dwepcrack.html
COMMENT=	Dwepcrack uses varioius methods to extract WEP keys

NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dwepcrack ${DESTDIR}${PREFIX}/bin

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
