# $NetBSD: Makefile,v 1.1 2014/10/30 13:29:59 noud4 Exp $
#

DISTNAME=	festvox_cmu_cr_tp_clunits16k
PKGNAME=	festvox-tp-1.1.1
CATEGORIES=	audio
MASTER_SITES=	http://festvox.org/packed/voices/croatian/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://festvox.org/packed/voices/croatian/
COMMENT=	Croatian male voice for the festival speech synthesis system
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-ogi>=2.0:../../audio/festlex-ogi	# ??
#festopt_clunits

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${FHOME}

.include "../../mk/bsd.pkg.mk"
