# $NetBSD: Makefile,v 1.7 2012/09/29 00:50:42 asau Exp $

DISTNAME=			gwhois_20080219.1
PKGNAME=			${DISTNAME:S/_/-/g}
PKGREVISION=			1
CATEGORIES=			net
MASTER_SITES=			http://gwhois.de/gwhois/

MAINTAINER=			mj@mjturner.net
HOMEPAGE=			http://gwhois.de/gwhois/
COMMENT=			Flexible whois client and proxy

USE_TOOLS+=			perl
REPLACE_PERL+=			gwhois

DEPENDS+=			p5-libwww>=5.4:../../www/p5-libwww
DEPENDS+=			lynx-[0-9]*:../../www/lynx

WRKSRC=				${WRKDIR}/${PKGNAME_NOREV}
INSTALLATION_DIRS=		share/${PKGBASE} ${PKGMANDIR}/man1

SUBST_CLASSES+=			fix-paths
SUBST_MESSAGE.fix-paths=	Fixing paths
SUBST_FILES.fix-paths=		gwhois
SUBST_FILES.fix-paths+=		gwhois.1
SUBST_SED.fix-paths+=		-e 's,/etc/gwhois,${PREFIX}/share/gwhois,g'
SUBST_STAGE.fix-paths=		post-patch

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gwhois ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gwhois.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/pattern ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
