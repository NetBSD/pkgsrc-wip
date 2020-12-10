# $NetBSD: Makefile,v 1.2 2015/05/03 13:20:34 thomasklausner Exp $

DISTNAME=	v0.3.0
PKGNAME=	${DISTNAME:S/v/sipvicious-/}
CATEGORIES=	security
MASTER_SITES=	https://github.com/EnableSecurity/sipvicious/archive/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.sipvicious.org/
COMMENT=	SIPVicious is a SIP security tool suite
LICENSE=	gnu-gpl-v2

#DEPENDS+=	python>=3.0:../../lang/python

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=		# python scripts only
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} ./setup.py build

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} ./setup.py install
	cd ${WRKSRC}/man1 && ${INSTALL_DATA} *.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
