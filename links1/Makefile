# $NetBSD: Makefile,v 1.7 2004/09/06 10:48:10 thomasklausner Exp $
#

DISTNAME=		links-1.00pre11
PKGNAME=		links1-0.99.11
CATEGORIES=		www
MASTER_SITES=		http://artax.karlin.mff.cuni.cz/~mikulas/links/download/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://artax.karlin.mff.cuni.cz/~mikulas/links/
COMMENT=		Text browser with tables (original version)

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_PKG_CONFIG=""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/links ${PREFIX}/bin/links1
	${INSTALL_MAN} ${WRKSRC}/links.1 ${PREFIX}/man/man1/links1.1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
