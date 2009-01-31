# $NetBSD: Makefile,v 1.2 2009/01/31 23:39:00 jym-netbsd Exp $
#

DISTNAME=	5440DL_lin64bit_1_2_1
PKGNAME=	cups-driver-Magicolor5440DL-1.2.1
CATEGORIES=	print
MASTER_SITES=	http://printer.konicaminolta.net/drivers/linux/
EXTRACT_SUFX=	.zip

PKG_DESTDIR_SUPPORT=    user-destdir

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://printer.konicaminolta.com/support/current_printers/mc5440dl_sup.htm
COMMENT=	CUPS driver for printer Konica Minolta Magicolor 5440DL

WRKSRC=		${WRKDIR}/5440dl_64_v1.2.1/magicolor5440DL-1.2.1/

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

BUILD_DEPENDS+=	jbigkit>=1.6:../../wip/jbigkit
DEPENDS+=	cups>=1.1.14:../../print/cups
DEPENDS+=	ghostscript>=8.0:../../print/ghostscript

post-extract:
	cd ${WRKDIR}/5440dl_64_v1.2.1/; \
		extract_file=src/magicolor5440dl-1.2.1.tar.gz; ${EXTRACT_CMD}

.include "../../graphics/lcms/buildlink3.mk"
.include "../../wip/jbigkit/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
