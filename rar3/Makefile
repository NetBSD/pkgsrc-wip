# $NetBSD: Makefile,v 1.9 2007/08/05 15:04:26 othyro Exp $

DISTNAME=		rarbsd-3.7.0
PKGNAME=		rar-3.7.0
WRKSRC=			${WRKDIR}/rar
CATEGORIES=		archivers
MASTER_SITES=		http://www.rarlab.com/rar/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rarlab.com/
COMMENT=		File archiver (binary only)

EGDIR=			${PREFIX}/share/examples/rar3
CONF_FILES=		${EGDIR}/rarfiles.lst ${PKG_SYSCONFDIR}/rarfiles.lst

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1

ONLY_FOR_PLATFORM=	FreeBSD-*-i386 NetBSD-*-i386

NO_BUILD=		yes
NO_CONFIGURE=		yes

RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

DATA_FILES=		file_id.diz license.txt order.htm rar.txt \
			readme.txt technote.txt whatsnew.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${PREFIX}/bin/rar3
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin/unrar3
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${PREFIX}/${PKGMANDIR}/cat1/rar3.0
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${PREFIX}/etc/rarfiles.lst
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${PREFIX}/lib/default.sfx
	${INSTALL_DATA_DIR} ${PREFIX}/share/rar3
	for a in ${DATA_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${PREFIX}/share/rar3/$$a; \
	done

.include "../../mk/bsd.pkg.mk"
