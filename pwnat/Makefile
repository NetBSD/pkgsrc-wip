# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:44 thomasklausner Exp $

DISTNAME=	pwnat-0.3
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://samy.pl/pwnat/
COMMENT=	NAT to NAT client-server communication
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

GIT_REPOSITORIES=	samyk
GIT_REPO.samyk=		git://github.com/samyk/${PKGBASE}.git
GIT_MODULE.samyk=	${PKGBASE}
WRKSRC=			${WRKDIR}/${PKGBASE}

USE_TOOLS=		gmake
NO_CONFIGURE=		YES
INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/doc/${PKGBASE}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-docutils

post-build:
	${PREFIX}/bin/rst2man.py ${FILESDIR}/pwnat.8.rst > ${WRKSRC}/pwnat.8

do-install:
	${INSTALL_DATA}    ${WRKSRC}/COPYING-pingtunnel ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA}    ${WRKSRC}/Changes            ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA}    ${WRKSRC}/README             ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA}    ${WRKSRC}/README-udptunnel   ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_PROGRAM} ${WRKSRC}/pwnat              ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN}     ${WRKSRC}/pwnat.8            ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../wip/mk/git-package.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
