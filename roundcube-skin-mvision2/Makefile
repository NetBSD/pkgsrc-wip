# $NetBSD: Makefile,v 1.4 2009/12/13 13:31:02 pettai Exp $
#

DISTNAME=	mvision2.2
PKGNAME=	roundcube-skin-mvision-2.2
CATEGORIES=	mail
MASTER_SITES=	http://roundcubethemes.net/downloads/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://roundcubethemes.net/
COMMENT=	Hotmail/MSN-stylish skin for roundcube webmail

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	roundcube>=0.2-stable:../../mail/roundcube
WRKSRC=		${WRKDIR}/mvision2_en
USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	share/roundcube/skins

do-install:
	${CP} -R ${WRKDIR}/mvision2_en ${DESTDIR}${PREFIX}/share/roundcube/skins/

.include "../../mk/bsd.pkg.mk"
