# $NetBSD: Makefile,v 1.4 2011/08/23 12:39:31 christtrekker Exp $
#

DISTNAME=	fntsample-3.2
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fntsample/}

DISTFILES=	${DEFAULT_DISTFILES} Blocks.txt
SITES.Blocks.txt=	http://unicode.org/Public/UNIDATA/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fntsample.sourceforge.net/
COMMENT=	Make font samples, similar to Unicode charts, showing Unicode coverage
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	share/unicode

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=	pkg-config gmake perl:run
REPLACE_PERL=	pdfoutline.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-unicode-blocks=${DESTDIR}${PREFIX}/share/unicode/Blocks.txt

pre-configure:
	${MKDIR} ${DESTDIR}${PREFIX}/share/unicode
	${CP} ${DISTDIR}/Blocks.txt ${DESTDIR}${PREFIX}/share/unicode

.include "../../devel/glib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
