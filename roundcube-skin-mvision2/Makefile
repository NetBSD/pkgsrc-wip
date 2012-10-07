# $NetBSD: Makefile,v 1.5 2012/10/07 14:53:44 asau Exp $
#

DISTNAME=	mvision2.2
PKGNAME=	roundcube-skin-mvision-2.2
CATEGORIES=	mail
MASTER_SITES=	http://roundcubethemes.net/downloads/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://roundcubethemes.net/
COMMENT=	Hotmail/MSN-stylish skin for roundcube webmail

DEPENDS+=	roundcube>=0.2-stable:../../mail/roundcube
WRKSRC=		${WRKDIR}/mvision2_en
USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	share/roundcube/skins

do-install:
	${CP} -R ${WRKDIR}/mvision2_en ${DESTDIR}${PREFIX}/share/roundcube/skins/

.include "../../mk/bsd.pkg.mk"
