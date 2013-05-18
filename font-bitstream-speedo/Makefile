# $NetBSD: Makefile,v 1.1 2013/05/18 21:35:39 othyro Exp $
#

DISTNAME=	font-bitstream-speedo-1.0.2
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Bitstream Speedo fonts
#LICENSE=	# XXX mit?

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	mkfontdir mkfontscale
FONTS_DIRS.x11=	share/fonts/X11/Speedo

CONFIGURE_ARGS+=	--with-fontrootdir=${PREFIX}/share/fonts/X11

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
