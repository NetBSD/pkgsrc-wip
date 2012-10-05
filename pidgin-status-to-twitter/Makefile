# $NetBSD: Makefile,v 1.2 2012/10/05 11:31:52 asau Exp $
#

DISTNAME=		status_to_twitter
PKGNAME=		pidgin-${DISTNAME:S|_|-|g}-0.1
CATEGORIES=		chat net
MASTER_SITES=		http://pidgin-status-to-twitter.googlecode.com/files/
EXTRACT_SUFX=		.pl

MAINTAINER=		noud@home.nl
HOMEPAGE=		http://code.google.com/p/pidgin-status-to-twitter/
COMMENT=		Update Twitter with your Pidgin status
LICENSE=		gnu-gpl-v3

DEPENDS+=		p5-Net-Twitter-[0-9]*:../../net/p5-Net-Twitter

WRKSRC=			${WRKDIR}
NO_BUILD=		yes

PLIST_SUBST+=		DISTNAME=${DISTNAME}
PLIST_SUBST+=		EXTRACT_SUFX=${EXTRACT_SUFX}

INSTALLATION_DIRS+=	lib/purple-2

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} ${DESTDIR}${PREFIX}/lib/purple-2

.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
