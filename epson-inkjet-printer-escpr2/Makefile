# $NetBSD$

DISTNAME=	epson-inkjet-printer-escpr2-1.1.62
CATEGORIES=	print
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/14/47/10/84d0ad36f1333fb1cae822976df1f611b7c2f6a0/
DISTFILES=	epson-inkjet-printer-escpr2-1.1.62-1lsb3.2.src.rpm

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://download.ebz.epson.net/dsc/search/01/search/?OSC=LX
COMMENT=	Epson Inkjet Printer (ESC/P-R) Driver 2
LICENSE=	gnu-gpl-v2

USE_TOOLS=	rpm2pkg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cupsfilterdir=${PREFIX}/libexec/cups/filter \
		--with-cupsppddir=${PREFIX}/share/ppd/cupsfilters
# USE_LIBTOOL=	yes

post-extract:
	cd ${WRKDIR} && pax -rzf ${DISTNAME}-1lsb3.2.tar.gz

.include "../../print/cups-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
