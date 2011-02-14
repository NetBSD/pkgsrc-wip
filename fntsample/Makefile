# $NetBSD: Makefile,v 1.1.1.1 2011/02/14 21:22:59 christtrekker Exp $
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

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-unicode-blocks=${PREFIX}/share/unicode/Blocks.txt

pre-configure:
	${CP} ${DISTDIR}/Blocks.txt ${PREFIX}/share/unicode

.include "../../mk/bsd.pkg.mk"
