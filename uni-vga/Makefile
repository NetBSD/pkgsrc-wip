# $NetBSD: Makefile,v 1.1 2011/10/19 18:39:23 mwilhelmy Exp $
#

DISTNAME=	uni-vga
PKGNAME=	${DISTNAME}-1
EXTRACT_SUFX=	.tgz
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.inp.nsk.su/~bolkhov/files/fonts/univga/

MAINTAINER=	mw+pkgsrc@wzff.de
HOMEPAGE=	http://www.inp.nsk.su/~bolkhov/files/fonts/univga/
COMMENT=	Monospaced Unicode font based on the original IBM VGA font
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=		bdftopcf gzip

FONTDIR=		${PREFIX}/lib/X11/fonts/uni-vga
FONTS_DIRS.x11+=	${FONTDIR}
OWN_DIRS=		${FONTDIR}
WRKSRC=			${WRKDIR}/uni_vga

INSTALLATION_DIRS=	${FONTDIR}

do-build:
	bdftopcf -o ${WRKSRC}/u_vga16.pcf ${WRKSRC}/u_vga16.bdf
	gzip -9 ${WRKSRC}/u_vga16.pcf

do-install:
	${INSTALL_DATA} ${WRKSRC}/u_vga16.pcf.gz ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
