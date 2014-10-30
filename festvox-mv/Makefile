# $NetBSD: Makefile,v 1.2 2014/10/30 13:32:45 noud4 Exp $
#

DISTNAME=	hy_fi_mv_diphone-20041119
PKGNAME=	festvox-mv-20041119
CATEGORIES=	audio
MASTER_SITES=	http://www.ling.helsinki.fi/suopuhe/download/ \
		http://festvox.org/packed/voices/finnish/
EXTRACT_SUFX=	.tgz

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://www.ling.helsinki.fi/suopuhe/
COMMENT=	Finnish voice for the festival speech synthesis system
#LICENSE=	# TODO: (see mk/license.mk) Gnu Lesser General Public License

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-ogi>=2.0:../../audio/festlex-ogi	# ??

USE_TOOLS+=	pax
WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes
FHOME=		${PREFIX}/share/festival
REPLACE_PERL=	lib/voices/finnish/hy_fi_mv_diphone/festvox/suopuhe_filter.perl

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${FHOME}

.include "../../mk/bsd.pkg.mk"
