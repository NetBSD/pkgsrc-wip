# $NetBSD: Makefile,v 1.22 2012/10/03 08:39:35 asau Exp $
#

DISTNAME=		links-1.00pre20
PKGNAME=		${DISTNAME:S/links/links1/}
PKGREVISION=		2
CATEGORIES=		www
MASTER_SITES=		http://artax.karlin.mff.cuni.cz/~mikulas/links/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://artax.karlin.mff.cuni.cz/~mikulas/links/
COMMENT=		Text browser with tables (original version)

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_PKG_CONFIG=""

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/links ${PREFIX}/bin/links1
	${INSTALL_MAN} ${WRKSRC}/links.1 ${PREFIX}/${PKGMANDIR}/man1/links1.1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
