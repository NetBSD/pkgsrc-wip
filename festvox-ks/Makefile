# $NetBSD: Makefile,v 1.2 2014/10/30 13:32:45 noud4 Exp $
#

DISTNAME=	pjwstk_ks_multisyn_mbrola
PKGNAME=	festvox-ks-1.1.1
CATEGORIES=	audio
MASTER_SITES=	http://festvox.org/packed/voices/polish/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://festvox.org/packed/voices/polish/
COMMENT=	Polish voice for the festival speech synthesis system
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-ogi>=2.0:../../audio/festlex-ogi	# ??

USE_TOOLS+=	pax
WRKSRC=		${WRKDIR}/lib
NO_BUILD=	yes
FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}/lib/etc
	cd ${WRKSRC}/etc && pax -rw * ${DESTDIR}${FHOME}/lib/etc
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}/lib/voices
	cd ${WRKSRC}/voices && pax -rw * ${DESTDIR}${FHOME}/lib/voices

.include "../../mk/bsd.pkg.mk"
