# $NetBSD: Makefile,v 1.1.1.1 2010/11/23 05:01:35 ryo-on Exp $
#

DISTNAME=	nicovideo-dl-0.0.20091209
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=nicovideo-dl/44836/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://sourceforge.jp/projects/nicovideo-dl/
COMMENT=	Download videos from www.nicovideo.jp
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/nicovideo-dl-0.0.20091209
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

REPLACE_PYTHON+=	nicovideo-dl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nicovideo-dl ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
