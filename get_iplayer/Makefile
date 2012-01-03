# $NetBSD: Makefile,v 1.2 2012/01/03 13:29:51 shattered Exp $
#

DISTNAME=	get_iplayer-2.80
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.infradead.org/pub/get_iplayer/

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	http://www.infradead.org/get_iplayer/html/get_iplayer.html
COMMENT=	Search, index, record or stream BBC iPlayer broadcasts
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-HTML-Parser>=3.0:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTTP-Cookies>=6.0:../../www/p5-HTTP-Cookies
DEPENDS+=	p5-HTTP-Date>=6.0:../../www/p5-HTTP-Date
DEPENDS+=	p5-libwww>=6.0:../../www/p5-libwww
DEPENDS+=	rtmpdump>=1.8:../../net/rtmpdump
DEPENDS+=	flvstreamer>=1.8:../../wip/flvstreamer

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_LANGUAGES=	# none
NO_BUILD=	yes
REPLACE_PERL=	get_iplayer

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/get_iplayer ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/get_iplayer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
