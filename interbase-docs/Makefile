# $NetBSD: Makefile,v 1.1.1.1 2004/01/01 19:26:22 mpasternak Exp $
#

DISTNAME=		60All
PKGNAME=		interbase-docs-6.0
WRKSRC=			${WRKDIR}
CATEGORIES=		databases
MASTER_SITES=		http://www.ibphoenix.com/downloads/
EXTRACT_SUFX=		.zip

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.firebirdsql.org/index.php?op=doc&id=userdoc
COMMENT=		Documentation for InterBase 6.0 in PDF format

NO_BIN_ON_CDROM=	"I am not sure if we can redistribute it"
NO_SRC_ON_CDROM=	${NO_BIN_ON_CDROM}
NO_BUILD=		# defined

ID6_DIR=       		${PREFIX}/share/doc/${PKGNAME}
ID6_FILES=		apiguide.pdf datadef.pdf devguide.pdf embedsql.pdf \
			getstart.pdf langref.pdf opguide.pdf
			
do-install:
	${INSTALL_DATA_DIR} ${ID6_DIR}
	for a in ${ID6_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${ID6_DIR}/$$a; done		

.include "../../mk/bsd.pkg.mk"
