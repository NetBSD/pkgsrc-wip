# $NetBSD: Makefile,v 1.9 2013/12/12 11:37:14 gschwarz Exp $

DISTNAME=	dwepcrack-0.4
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	https://web.archive.org/web/20120103232602if_/http://www.e.kth.se/%7Epvz/wifi/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20070322102507/http://www.dachb0den.com/projects/dwepcrack.html
COMMENT=	Dwepcrack uses varioius methods to extract WEP keys

EXTRACT_CMD=	${TAR} xf $$extract_file

NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dwepcrack ${DESTDIR}${PREFIX}/bin

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
