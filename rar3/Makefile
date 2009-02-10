# $NetBSD: Makefile,v 1.10 2009/02/10 04:11:02 othyro Exp $

DISTNAME=		rarbsd-3.8.0
PKGNAME=		rar-3.8.0
WRKSRC=			${WRKDIR}/rar
CATEGORIES=		archivers
MASTER_SITES=		http://www.rarlab.com/rar/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rarlab.com/
COMMENT=		File archiver (binary only)

EGDIR=			${PREFIX}/share/examples/rar3

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1

ONLY_FOR_PLATFORM=	FreeBSD-*-i386 NetBSD-*-i386

NO_BUILD=		yes
NO_CONFIGURE=		yes

RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

LICENSE=		rar3-license
LICENSE_FILE=		${FILESDIR}/rar3-license

DATA_FILES=		file_id.diz license.txt order.htm rar.txt \
			readme.txt technote.txt whatsnew.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${PREFIX}/bin/rar3
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin/unrar3
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${PREFIX}/${PKGMANDIR}/cat1/rar3.0
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${EGDIR}/rarfiles.lst
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${PREFIX}/lib/default.sfx
	${INSTALL_DATA_DIR} ${PREFIX}/share/rar3
	for a in ${DATA_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${PREFIX}/share/rar3/$$a; \
	done

.include "../../mk/bsd.pkg.mk"
