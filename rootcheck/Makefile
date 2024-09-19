# $NetBSD: Makefile,v 1.4 2012/12/09 03:56:52 othyro Exp $
#

DISTNAME=	rootcheck-2.4
CATEGORIES=	security
MASTER_SITES=	http://www.ossec.net/rootcheck/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ossec.net/rootcheck/
COMMENT=	RootKit detection software
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin share/${PKGBASE}/db share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ossec-rootcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/rootcheck.conf ${DESTDIR}${PREFIX}/share/rootcheck/
	${INSTALL_DATA} ${WRKSRC}/db/*.txt ${DESTDIR}${PREFIX}/share/rootcheck/db/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/rootcheck/

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
