# $NetBSD: Makefile,v 1.1.1.1 2007/07/16 14:13:42 krub1 Exp $

DISTNAME=	usbids-10032007
CATEGORIES=	misc
MASTER_SITES=	http://www.coris.org.uk/mrk/pkgsrc/

MAINTAINER=	mkirby@NetBSD.org
HOMEPAGE=	http://www.linux-usb.org/usb.ids
COMMENT=	Repository of USB vendor id's

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes

WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/usbids
	${INSTALL_DATA} ${WRKSRC}/usb.ids ${DESTDIR}${PREFIX}/share/usbids

.include "../../mk/bsd.pkg.mk"
