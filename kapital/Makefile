# $NetBSD: Makefile,v 1.1.1.1 2003/06/04 00:22:48 jeremy-c-reed Exp $

DISTNAME=	kapital-1.1
CATEGORIES=	devel kde

MAINTAINER=	jnr@cwru.edu
HOMEPAGE=	http://www.thekompany.com/products/kapital/
COMMENT=	Personal finance manager

USE_BUILDLINK2=	YES

DOWNLOAD_PAGE=	http://www.thekompany.com/products/

LICENSE=		no-redistribution
RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

INTERACTIVE_STAGE=	fetch
_FETCH_MESSAGE= \
	${ECHO} "======================================================================"; \
	${ECHO} ; \
	${ECHO} " The file ${DISTNAME}${EXTRACT_SUFX} containing the"; \
	${ECHO} " Kapital source code must be downloaded "; \
	${ECHO} " into:"; \
	${ECHO} "	${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}"; \
	${ECHO} " from:"; \
	${ECHO} "	${DOWNLOAD_PAGE}"; \
	${ECHO} ; \
	${ECHO} " Choose 'Download version' from the Kapital section, add it to"; \
	${ECHO} "  your cart, checkout, registering if needed.  Once you get to "; \
	${ECHO} "  the downloads page, select the 'Source Download' item from the";\
	${ECHO} "  top of the list."; \
	${ECHO} ; \
	${ECHO} "======================================================================"

.include "../../new/korelib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
