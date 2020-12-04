# $NetBSD$

DISTNAME=	epson-inkjet-printer-escpr-1.7.7-1lsb3.2
PKGNAME=	epson-inkjet-printer-escpr-1.7.7
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/10/49/18/f3016be6120a7271a6d9cb64872f817bce1920b8/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://download.ebz.epson.net/dsc/search/01/search/?OSC=LX
COMMENT=	Epson Inkjet Printer Driver (ESC/P-R)
LICENSE=	gnu-gpl-v2

#USE_TOOLS=	gmake
WRKSRC=		${WRKDIR}/epson-inkjet-printer-escpr-1.7.7
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../print/cups-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
