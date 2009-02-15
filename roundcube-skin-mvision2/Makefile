# $NetBSD: Makefile,v 1.1.1.1 2009/02/15 22:38:13 pettai Exp $
#

DISTNAME=	mvision2.2
PKGNAME=	roundcube-skin-mvision2
CATEGORIES=	mail
MASTER_SITES=	http://roundcubethemes.net/downloads/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://roundcubethemes.net/
COMMENT=	Hotmail/MSN-stylish skin for roundcube webmail

DEPENDS+=	roundcube>=0.2-stable:../../mail/roundcube
WRKSRC=		${WRKDIR}/mvision2_en
USE_LANGUAGES=	# none

NO_BUILD=	no

do-install:
	${CP} -R ${WRKDIR}/mvision2_en ${DESTDIR}${PREFIX}/share/roundcube/skins/

.include "../../mk/bsd.pkg.mk"
