# $NetBSD: Makefile,v 1.1 2005/03/12 23:18:44 jcflack Exp $
#

DISTNAME=		partlibrary-2.0.1.2-1
PKGNAME=		qcad-partlibrary-2.0.1.2

CATEGORIES=		cad
MASTER_SITES=		http://www.ribbonsoft.com/archives/partlibrary/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ribbonsoft.com/qcad/
COMMENT=	About 4500 mech, elec, etc. parts for the QCad 2D CAD system

NO_CONFIGURE=	yes
NO_BUILD=	yes

DEPENDS+=	qcad>=2.0.0.0:../../wip/qcad  # wip should be cad

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/qcad/library
	cd ${WRKSRC} && umask 022 && ${PAX} -rwpm . ${PREFIX}/share/qcad/library

.include "../../mk/bsd.pkg.mk"
