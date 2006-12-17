# $NetBSD: Makefile,v 1.17 2006/12/17 19:32:21 thomasklausner Exp $
#

DISTNAME=		links-1.00pre19
PKGNAME=		${DISTNAME:S/links/links1/}
CATEGORIES=		www
MASTER_SITES=		http://artax.karlin.mff.cuni.cz/~mikulas/links/download/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://artax.karlin.mff.cuni.cz/~mikulas/links/
COMMENT=		Text browser with tables (original version)

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_PKG_CONFIG=""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/links ${PREFIX}/bin/links1
	${INSTALL_MAN} ${WRKSRC}/links.1 ${PREFIX}/${PKGMANDIR}/man1/links1.1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
