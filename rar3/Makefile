# $NetBSD: Makefile,v 1.12 2009/05/19 09:00:12 thomasklausner Exp $

DISTNAME=		rarbsd-3.8.0
PKGNAME=		rar-3.8.0
WRKSRC=			${WRKDIR}/rar
CATEGORIES=		archivers
MASTER_SITES=		http://www.rarlab.com/rar/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rarlab.com/
COMMENT=		File archiver (binary only)
LICENSE=		rar3-license

RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
LICENSE_FILE=		${FILESDIR}/rar3-license

EGDIR=			${PREFIX}/share/examples/rar3

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1

ONLY_FOR_PLATFORM=	FreeBSD-*-i386 NetBSD-*-i386

NO_BUILD=		yes
NO_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	user-destdir

DATA_FILES=		file_id.diz license.txt order.htm rar.txt \
			readme.txt technote.txt whatsnew.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${DESTDIR}/${PREFIX}/bin/rar3
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${DESTDIR}/${PREFIX}/bin/unrar3
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${DESTDIR}/${PREFIX}/${PKGMANDIR}/cat1/rar3.0
	${INSTALL_DATA_DIR} ${DESTDIR}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${DESTDIR}/${EGDIR}/rarfiles.lst
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${DESTDIR}/${PREFIX}/lib/default.sfx
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/share/rar3
	for a in ${DATA_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${DESTDIR}/${PREFIX}/share/rar3/$$a; \
	done

.include "../../mk/bsd.pkg.mk"
