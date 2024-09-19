# $NetBSD: Makefile,v 1.4 2012/10/07 14:53:43 asau Exp $

PKGVERSION=		4.10beta5
DISTNAME=		rarbsd-${PKGVERSION:S/0beta/.b/}
PKGNAME=		rar-${PKGVERSION}
WRKSRC=			${WRKDIR}/rar
CATEGORIES=		archivers
MASTER_SITES=		http://www.rarlab.com/rar/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.rarlab.com/
COMMENT=		File archiver (binary only)
LICENSE=		rar4-license

RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
LICENSE_FILE=		${FILESDIR}/rar4-license

EGDIR=			${PREFIX}/share/examples/rar4

INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/cat1 share/rar4

ONLY_FOR_PLATFORM=	FreeBSD-*-i386 NetBSD-*-i386

NO_BUILD=		yes
NO_CONFIGURE=		yes

DATA_FILES=		license.txt order.htm rar.txt readme.txt technote.txt \
			whatsnew.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${DESTDIR}${PREFIX}/bin/rar4
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${DESTDIR}${PREFIX}/bin/unrar4
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/rar4.0
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${DESTDIR}${EGDIR}/rarfiles.lst
	${INSTALL_LIB} ${WRKSRC}/default.sfx ${DESTDIR}${PREFIX}/lib/default.sfx
	for a in ${DATA_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${DESTDIR}${PREFIX}/share/rar4/$$a; \
	done

.include "../../mk/bsd.pkg.mk"
