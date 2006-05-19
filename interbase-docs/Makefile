# $NetBSD: Makefile,v 1.6 2006/05/19 16:51:19 ykomatsu Exp $
#

DISTNAME=		60All
PKGNAME=		interbase-docs-6.0
WRKSRC=			${WRKDIR}
CATEGORIES=		databases
MASTER_SITES=		http://www.ibphoenix.com/downloads/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.firebirdsql.org/index.php?op=doc&id=userdoc
COMMENT=		Documentation for InterBase 6.0 in PDF format

RESTRICTED=		I am not sure if we can redistribute it
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BUILD=		yes

ID6_DIR=       		${PREFIX}/share/doc/${PKGNAME}
ID6_FILES=		apiguide.pdf datadef.pdf devguide.pdf embedsql.pdf \
			getstart.pdf langref.pdf opguide.pdf

do-install:
	${INSTALL_DATA_DIR} ${ID6_DIR}
	for a in ${ID6_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${ID6_DIR}/$$a; done

.include "../../mk/bsd.pkg.mk"
