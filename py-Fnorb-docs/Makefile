# $NetBSD: Makefile,v 1.6 2012/10/06 15:45:33 asau Exp $
#

DISTNAME=		Fnorb-Guide.html
PKGNAME=		py-Fnorb-docs-0
WRKSRC=			${WRKDIR}/Fnorb-Guide
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fnorb/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://fnorb.sourceforge.net/
COMMENT=		Documentation for py-Fnorb in HTML format

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax

HTMLDIR=	share/doc/${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${WRKSRC} && pax -rw -pe * ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
