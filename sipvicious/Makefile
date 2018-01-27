# $NetBSD: Makefile,v 1.2 2015/05/03 13:20:34 thomasklausner Exp $

DISTNAME=	sipvicious-0.2.8
CATEGORIES=	security
MASTER_SITES=	http://sipvicious.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.sipvicious.org/
COMMENT=	SIPVicious is a SIP security tool suite
LICENSE=	gnu-gpl-v2

PYTHON_SCRIPTS=	svcrack.py svcrash.py svmap.py svreport.py svwar.py

USE_LANGUAGES=		#perl scripts only
NO_BUILD=		YES
REPLACE_PYTHON+=	${PYTHON_SCRIPTS}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
.for script in ${PYTHON_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${script} ${DESTDIR}${PREFIX}/bin
.endfor
.for man in ${PYTHON_SCRIPTS:S/.py/.1/g}
	${INSTALL_DATA} ${WRKSRC}/man1/${man} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
