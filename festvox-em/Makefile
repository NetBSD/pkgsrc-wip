# $NetBSD: Makefile,v 1.2 2014/10/30 13:32:45 noud4 Exp $
#

DISTNAME=	festvox_cstr_pl_em_diphone
PKGNAME=	festvox-em-1.1.1
CATEGORIES=	audio
MASTER_SITES=	http://festvox.org/packed/voices/polish/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://festvox.org/packed/voices/polish/
COMMENT=	Polish voice for the festival speech synthesis system
#LICENSE=	# TODO: (see mk/license.mk) non-commercial use

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-ogi>=2.0:../../audio/festlex-ogi	# ??

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/festival

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
