# $NetBSD: Makefile,v 1.1.1.1 2004/02/09 01:27:43 mpasternak Exp $
#

DISTNAME=		rarbsd-3.3.0
PKGNAME=		rar-3.3.0
WRKSRC=			${WRKDIR}/rar
CATEGORIES=		archivers
MASTER_SITES=		http://files10.rarlab.com/rar/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://files10.rarlab.com/rar/
COMMENT=		File archiver (binary only)

ONLY_FOR_PLATFORM=	FreeBSD-*-i386

NO_BUILD=		# defined
NO_CONFIGURE=		# defined

NO_BIN_ON_CDROM=	"Only unmodified original package can be distributed"
NO_BIN_ON_FTP=		${NO_BIN_ON_CDROM}

DATA_FILES=		file_id.diz license.txt order.htm rar.txt \
			rar_faq.txt readme.txt technote.txt whatsnew.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${PREFIX}/bin/rar3
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin/unrar3
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${PREFIX}/man/cat1/rar3.1
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${PREFIX}/etc/rarfiles.lst
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${PREFIX}/lib/default.sfx
	${INSTALL_DATA_DIR} ${PREFIX}/share/rar3
	for a in ${DATA_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${PREFIX}/share/rar3/$$a; \
	done

.include "../../mk/bsd.pkg.mk"
