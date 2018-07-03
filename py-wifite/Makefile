# $NetBSD: Makefile,v 1.2 2014/05/09 07:38:51 thomasklausner Exp $
#

DISTNAME=	wifite-2.0r85
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net security
MASTER_SITES=	http://wifite.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wifite.googlecode.com/
COMMENT=	Automated wireless auditor
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
#NO_CONFIGURE=	yes
NO_BUILD=	yes
REPLACE_PYTHON=	wifite.py
PLIST_SUBST+=	PYVERPREFIX=${PYPKGPREFIX}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # XXX See TODO

DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	bin ${DOCDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wifite.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/HELP.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/${DOCDIR}

DEPENDS+=	aircrack-ng-[0-9]*:../../wip/aircrack-ng
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
