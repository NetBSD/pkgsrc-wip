# $NetBSD: Makefile,v 1.4 2012/10/03 21:32:48 asau Exp $
#

DISTNAME=	outguess-0.2
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://mirror.sweon.net/madchat/crypto/stegano/unix/jpeg/ \
		http://www.outguess.org/ \
		ftp://ftp.fu-berlin.de/unix/security/outguess/ \
		http://www.mirrors.wiretapped.net/security/steganography/outguess/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.outguess.org/
COMMENT=	JPEG steganography tool
LICENSE=	original-bsd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${OG_DOCSDIR} ${OG_EGDIR}

OG_DOCSDIR=	share/doc/outguess
OG_EGDIR=	share/examples/outguess
OG_DOCS=	README STIRMARK-README
OG_EXAMPLES=	seek_script

WRKSRC=		${WRKDIR}/outguess
GNU_CONFIGURE=	yes

post-install:
.for file in ${OG_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/${OG_DOCSDIR}
.endfor
.for file in ${OG_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/${OG_EGDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
