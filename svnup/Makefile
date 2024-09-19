# $NetBSD: Makefile,v 1.1 2014/09/06 21:34:58 thomasklausner Exp $

DISTNAME=	svnup-1.05
CATEGORIES=	devel scm
MASTER_SITES=	http://jcm.dsl.visi.com/freebsd/svnup/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jcm.dsl.visi.com/freebsd/svnup/
COMMENT=	Lightweight program to pull source files from subversion
LICENSE=	2-clause-bsd

BUILDLINK_TRANSFORM+=	rm:-Werror
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 share/examples/svnup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/svnup ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/svnup.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/svnup.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/svnup.conf ${DESTDIR}${PREFIX}/share/examples/svnup

.include "../../mk/bsd.pkg.mk"
