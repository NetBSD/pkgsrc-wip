# $NetBSD: Makefile,v 1.1.1.1 2008/06/05 22:27:41 schnoebe Exp $

# First paragraph - distfile and binary package data
# DISTNAME PKGNAME PKGREVISION SVR4_PKGNAME CATEGORIES MASTER_SITES
# MASTER_SITE_SUBDIR EXTRACT_SUFX DISTFILES

DISTNAME=	udns_0.0.9
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://www.corpit.ru/mjt/udns/

# Second paragraph - MAINTAINER/OWNER, HOMEPAGE and COMMENT
MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.corpit.ru/mjt/udns.html
COMMENT=	Lightweight DNS resolver supporting asynchronous queries

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

# Third paragraph - licensing information
# Licences should be added to the pkgsrc/licenses directory.
# LICENSE=	gnu-lgpl-v2

# Fourth paragraph - PKG_INSTALLATION_TYPES
PKG_INSTALLATION_TYPES=	overwrite

# if the package can be created without root privileges
# PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

.include "options.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/libudns.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/dnsget ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/udns.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/udns.3 ${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/dnsget.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/rblcheck.1 ${PREFIX}/${PKGMANDIR}/man1

# Finally, please include bsd.pkg.mk
.include "../../mk/bsd.pkg.mk"
