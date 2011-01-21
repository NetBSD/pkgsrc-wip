# $NetBSD: Makefile,v 1.3 2011/01/21 13:04:06 ryo-on Exp $
#

DISTNAME=	nicovideo-dl-0.0.20091209
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=nicovideo-dl/44836/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/nicovideo-dl/
COMMENT=	Download videos from www.nicovideo.jp
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

REPLACE_PYTHON+=	nicovideo-dl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nicovideo-dl ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
