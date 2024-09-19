# $NetBSD$

DISTNAME=	epson-inkjet-printer-escpr-1.7.9-1lsb3.2
PKGNAME=	epson-inkjet-printer-escpr-1.7.9
#PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/12/50/95/322b8d6b915ab85add33d41f04ba5130866aadbe/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://download.ebz.epson.net/dsc/search/01/search/?OSC=LX
COMMENT=	Epson Inkjet Printer Driver (ESC/P-R)
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/epson-inkjet-printer-escpr-1.7.9
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-cupsfilterdir=${PREFIX}/libexec/cups/filter
CONFIGURE_ARGS+=	--with-cupsppddir=${PREFIX}/share/cups/model

.include "../../print/cups-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
