# $NetBSD: Makefile,v 1.2 2010/06/23 11:42:14 hfath Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${OG_DOCSDIR}

OG_DOCSDIR=	share/doc/outguess
OG_DOCS=	README STIRMARK-README

WRKSRC=		${WRKDIR}/outguess
GNU_CONFIGURE=	yes

post-install:
.for file in ${OG_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/${OG_DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
