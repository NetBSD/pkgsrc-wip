# $NetBSD$

DISTNAME=	input-ttf-1.2
CATEGORIES=	fonts
# this distfile is generated on-the-fly and differs every time
MASTER_SITES=	-https://input.djr.com/build/?fontSelection=whole&a=0&g=0&i=0&l=0&zero=0&asterisk=0&braces=0&preset=default&line-height=1.2&accept=I+do&email=
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://input.djr.com/
COMMENT=	Fonts for code from DJR & Font Bureau
LICENSE=	font-software-license

WRKSRC=	${WRKDIR}

INSTALLATION_DIRS+=	share/doc/input

NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

do-build:

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt  ${DESTDIR}${PREFIX}/share/doc/input
	${INSTALL_DATA} ${WRKSRC}/README.txt  ${DESTDIR}${PREFIX}/share/doc/input

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
