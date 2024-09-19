# $NetBSD: Makefile,v 1.2 2014/10/30 13:32:45 noud4 Exp $
#

DISTNAME=	festvox_nitech_us_slt_arctic_hts-2.0.1
PKGNAME=	festvox-slt-2.0.1
CATEGORIES=	audio
MASTER_SITES=	http://hts.sp.nitech.ac.jp/archives/2.0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://hts.sp.nitech.ac.jp/archives/2.0.1/
COMMENT=	US English female voice for the festival speech synthesis system
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	festival>=2.1:../../audio/festival
DEPENDS+=	festlex-ogi>=2.0:../../audio/festlex-ogi	# ??

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/lib
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

pre-install:
	${RM} ${WRKSRC}/hts.scm

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}/lib
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${FHOME}/lib

.include "../../mk/bsd.pkg.mk"
