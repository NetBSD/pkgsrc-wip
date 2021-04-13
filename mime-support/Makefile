# $NetBSD: Makefile,v 1.2 2012/10/03 14:14:57 asau Exp $
#

DISTNAME=		mime-support_3.62
PKGNAME=		mime-support-3.62
CATEGORIES=		mail
MASTER_SITES=		http://deb.debian.org/debian/pool/main/m/mime-support/

MAINTAINER=		silas_nfm21@nocafe.net
COMMENT=		Support commands for manipulating files using MIME and mailcap

USE_TOOLS+=		perl:run
WRKSRC=			${WRKDIR}/mime-support
NO_BUILD=		yes

REPLACE_PERL+=		run-mailcap

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

# Note: the mime-support provides other commands for managing /etc/mailcap:
#    but they're not necessary with pkgsrc and hence are ignored.
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run-mailcap ${DESTDIR}${PREFIX}/bin
	cd ${DESTDIR}${PREFIX}/bin; ${LN} run-mailcap mime-edit
	cd ${DESTDIR}${PREFIX}/bin; ${LN} run-mailcap mime-compose
	cd ${DESTDIR}${PREFIX}/bin; ${LN} run-mailcap mime-see
	cd ${DESTDIR}${PREFIX}/bin; ${LN} run-mailcap mime-print
	${INSTALL_MAN} ${WRKSRC}/run-mailcap.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/run-mailcap.1

.include "../../mk/bsd.pkg.mk"
