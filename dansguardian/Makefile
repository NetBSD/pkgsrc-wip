# $NetBSD: Makefile,v 1.1.1.1 2004/03/27 22:49:31 xtraeme Exp $

DISTNAME=	DansGuardian-2.6.1-11.source
PKGNAME=	dansguardian-2.6.1-11
CATEGORIES=	www
MASTER_SITES=	#

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.dansguardian.org/
COMMENT=	Fast, featureful web content filter for Squid proxy servers

WRKSRC=		${WRKDIR}/DansGuardian-2.6.1
HAS_CONFIGURE=	yes
USE_BUILDLINK2=	yes
MANCOMPRESSED=	yes
RCD_SCRIPTS=	dansguardian
USE_PKGINSTALL= YES

CONFIGURE_ARGS=		--prefix=${PREFIX} \
			--cgidir=/libexec/cgi-bin/ \
			--sysconfdir=/etc/dansguardian/ \
			--bindir=/sbin/ \
			--sysvdir=/etc/rc.d/ \
			--mandir=/man/ \
			--logdir=/var/log/

DEPENDS+=	squid>=2.5:../../www/squid

RESTRICTED=	"Redistribution is restricted."
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

DG_URL=		http://dansguardian.org/index.php?page=copyright2
DGD_URL=	http://dansguardian.org/index.php?page=download2

_FETCH_MESSAGE= 							\
	${ECHO} "======================================================================"; \
	${ECHO} ; 							\
	${ECHO} "Commercial source download is restricted.";		\
	${ECHO} "Please visit and read ${DG_URL}.";			\
	${ECHO} ;							\
	${ECHO} "To download ${DISTNAME}${EXTRACT_SUFX}, visit";	\
	${ECHO} "${DGD_URL}"; \
	${ECHO} ; 							\
	${ECHO} "======================================================================"

.include "../../www/apache/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
