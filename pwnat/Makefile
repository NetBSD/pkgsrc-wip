# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:44 thomasklausner Exp $

DISTNAME=	pwnat-0.3
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://samy.pl/pwnat/
COMMENT=	NAT to NAT client-server communication
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

GIT_REPOSITORIES=	samyk
GIT_REPO.samyk=	git://github.com/samyk/${PKGBASE}.git
GIT_MODULE.samyk=	${PKGBASE}
WRKSRC=		${WRKDIR}/${PKGBASE}

USE_TOOLS=		gmake
NO_CONFIGURE=		YES
INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/doc/${PKGBASE}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-docutils

post-build:
	${PREFIX:Q}/bin/rst2man.py ${FILESDIR:Q}/pwnat.8.rst > ${WRKSRC:Q}/pwnat.8

do-install:
	${INSTALL_DATA}    ${WRKSRC:Q}/COPYING-pingtunnel ${DESTDIR:Q}${PREFIX:Q}/share/doc/${PKGBASE:Q}
	${INSTALL_DATA}    ${WRKSRC:Q}/Changes            ${DESTDIR:Q}${PREFIX:Q}/share/doc/${PKGBASE:Q}
	${INSTALL_DATA}    ${WRKSRC:Q}/README             ${DESTDIR:Q}${PREFIX:Q}/share/doc/${PKGBASE:Q}
	${INSTALL_DATA}    ${WRKSRC:Q}/README-udptunnel   ${DESTDIR:Q}${PREFIX:Q}/share/doc/${PKGBASE:Q}
	${INSTALL_PROGRAM} ${WRKSRC:Q}/pwnat              ${DESTDIR:Q}${PREFIX:Q}/sbin
	${INSTALL_MAN}     ${WRKSRC:Q}/pwnat.8            ${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man8

.include "../../wip/mk/git-package.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
