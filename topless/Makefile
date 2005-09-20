# $NetBSD: Makefile,v 1.5 2005/09/20 06:15:34 obache Exp $
#

DISTNAME=	${PKGNAME_NOREV}-1.src.rpm
PKGNAME=	topless-1.49
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~daichi/src/
EXTRACT_SUFX=	# empty

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.ongs.net/~daichi/#topless
COMMENT=	Display and update information of target command like 'top'

BUILD_DEPENDS+=	rpm2pkg>=2.0:../../pkgtools/rpm2pkg

NO_BUILD=	yes

do-extract:
	${LOCALBASE}/sbin/rpm2pkg -d ${WRKDIR} ${DISTDIR}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/topless ${PREFIX}/bin/topless
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/topless
	${INSTALL_DATA} ${WRKDIR}/topless-license ${PREFIX}/share/doc/topless/LICENSE

.include "../../mk/bsd.pkg.mk"
