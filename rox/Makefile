# $NetBSD: Makefile,v 1.1.1.1 2003/12/04 22:25:30 anielski Exp $
#

DISTNAME=		rox-2.0.1
CATEGORIES=		sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=		aniou@smutek.pl
HOMEPAGE=		http://rox.sourceforge.net/
COMMENT=		RISC OS-like filer for X

USE_BUILDLINK2=	yes
USE_X11=        yes

post-patch:
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" < ${FILESDIR}/rox > \
		${WRKDIR}/${DISTNAME}/rox

do-build:
	${WRKDIR}/${DISTNAME}/ROX-Filer/AppRun --compile

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/rox/ROX-Filer
	${RM} -rf ${WRKDIR}/${DISTNAME}/ROX-Filer/src
	cd ${WRKDIR}/${DISTNAME}/ROX-Filer && ${PAX} -rw -pe . ${PREFIX}/share/rox/ROX-Filer
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" <                          \
		${WRKDIR}/${DISTNAME}/ROX-Filer/AppRun >                \
		${PREFIX}/share/rox/ROX-Filer/AppRun

	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/rox.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/rox
	${CP} -Rf ${WRKSRC}/Choices ${PREFIX}/share/rox
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/rox
	${CP} ${WRKSRC}/rox.xml ${PREFIX}/share/mime/
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/rox ${PREFIX}/bin

post-install:
	${PREFIX}/bin/update-mime-database ${PREFIX}/share/mime

post-deinstall:
	${PREFIX}/bin/update-mime-database ${PREFIX}/share/mime

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
