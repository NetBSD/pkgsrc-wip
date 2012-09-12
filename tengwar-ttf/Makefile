# $NetBSD: Makefile,v 1.1 2012/09/12 12:42:10 othyro Exp $
#

DISTNAME=	tengwar-ttf-20100611
CATEGORIES=	fonts
MASTER_SITES=	http://sourceforge.net/projects/freetengwar/files/TengwarFont/
EXTRACT_SUFX=	.zip
DISTFILES=	TengwarFormalCSUR11.zip FreeMonoTengwar.2010-06-11.zip
DISTFILES+=	TengwarTelcontar.008.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freetengwar.sourceforge.net/
COMMENT=	Family of fonts covering J. R. R. Tolkien's Tengwar script
LICENSE=	gnu-gpl-v3

#BUILD_DEPENDS+=	fontforge-[0-9]*:../../fonts/fontforge

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	lib/X11/fonts/TTF

FONTDIR=		${PREFIX}/lib/X11/fonts/TTF
FONTS_DIR.ttf=		${FONTDIR}

TENGWAR_FONTS=		FreeMonoTengwar.2010-06-11/FreeMonoTengwar.ttf
TENGWAR_FONTS+=		TengwarFormalCSUR11/TengwarFormalCSUR.ttf
TENGWAR_FONTS+=		tengtelc.ttf tengtelcb.ttf

do-install:
.for tfont in ${TENGWAR_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${tfont} ${DESTDIR}${FONTS_DIR.ttf}
.endfor

#.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
