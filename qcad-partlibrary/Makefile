# $NetBSD: Makefile$
#

DISTNAME=	partlibrary-2.0.1.2-1
PKGNAME=	qcad-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://www.ribbonsoft.com/archives/partlibrary/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qcad.org/qcad/
COMMENT=	About 4500 mech, elec, etc. parts for the QCad 2D CAD system
LICENSE=	gnu-gpl-v3

DEPENDS+=	qcad>=3.15.4.1:../../cad/qcad

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	find pax chmod
AUTO_MKDIRS=	yes

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} u=rw,go=r "{}" "+"

do-install:
	cd ${WRKSRC} && ${PAX} -rwpm architecture electrical \
	    electronics mechanical misc processing zipf_libs \
	    ${DESTDIR}${PREFIX}/share/qcad/libraries

.include "../../mk/bsd.pkg.mk"
