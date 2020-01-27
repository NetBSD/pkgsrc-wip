# $NetBSD: Makefile,v 1.4 2018/03/01 13:59:11 mef Exp $
#

V=		5.1.0
DISTNAME=	kicad-doc-${V}
CATEGORIES=	cad
MASTER_SITES=	https://kicad-downloads.s3.cern.ch/docs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kicad-pcb.org/
COMMENT=	Documentation for the PCB CAD software
LICENSE=	gnu-gpl-v3
NO_BUILD=	yes

DOCDIR=		${DESTDIR}${PREFIX}/share/doc/kicad

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${CP} -R ${WRKSRC}/share/doc/kicad/help ${DOCDIR}/
	${FIND} ${DOCDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DOCDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
