# $NetBSD: Makefile,v 1.3 2011/08/22 21:49:25 christtrekker Exp $
#

DISTNAME=	fntsample-3.2
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fntsample/}

DISTFILES=	${DEFAULT_DISTFILES} Blocks.txt
SITES.Blocks.txt=	http://unicode.org/Public/UNIDATA/

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://fntsample.sourceforge.net/
COMMENT=	Make font samples, similar to Unicode charts, showing Unicode coverage
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	share/unicode

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-unicode-blocks=${PREFIX}/share/unicode/Blocks.txt

pre-configure:
	${MKDIR} ${PREFIX}/share/unicode
	${CP} ${DISTDIR}/Blocks.txt ${PREFIX}/share/unicode

.include "../../devel/glib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
