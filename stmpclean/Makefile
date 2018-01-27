# $NetBSD: Makefile,v 1.8 2012/11/25 23:32:31 othyro Exp $
#

DISTNAME=	stmpclean-0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://shlang.com/stmpclean/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://shlang.com/stmpclean/
COMMENT=	Secure /tmp cleaner
LICENSE=	gnu-gpl-v2

DOCDIR=		${PREFIX}/share/doc/stmpclean

INSTALLATION_DIRS=	sbin ${DOCDIR}	${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stmpclean ${DESTDIR}${PREFIX}/sbin/stmpclean
	${INSTALL_DATA} ${WRKSRC}/stmpclean.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
