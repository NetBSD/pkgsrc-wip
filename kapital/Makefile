# $NetBSD: Makefile,v 1.22 2012/10/01 21:57:33 asau Exp $

DISTNAME=	kapital-1.1.030606
PKGREVISION=	5
CATEGORIES=	devel kde

MAINTAINER=	greyskyy@users.sourceforge.net
HOMEPAGE=	http://www.thekompany.com/products/kapital/
COMMENT=	Personal finance manager
LICENSE=		no-redistribution

RESTRICTED=		Redistribution not permitted
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

DOWNLOAD_PAGE=	http://www.thekompany.com/products/

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


USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=  ${WRKSRC}/ltconfig
SHLIBTOOL_OVERRIDE=	libtool

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
