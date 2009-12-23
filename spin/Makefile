# $NetBSD: Makefile,v 1.5 2009/12/23 08:40:14 jihbed Exp $
#

DISTNAME=	spin524
PKGNAME=	spin-5.2.4
CATEGORIES=	devel
MASTER_SITES=	http://spinroot.com/spin/Src/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://spinroot.com/spin/whatispin.html
COMMENT=	Spin is an efficient on-the-fly verification system
#LICENSE=	Spin Public license http://www.spinroot.com/spin/spin_license.html

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=		${WRKDIR}/Spin
USE_TOOLS+=	flex gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/spin share/examples/spin

do-build:
	cd ${WRKSRC}/Src5.2.4 && ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src5.2.4/spin \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Doc/* \
		${DESTDIR}${PREFIX}/share/doc/spin
	${INSTALL_DATA} ${WRKSRC}/Test/* \
		${DESTDIR}${PREFIX}/share/examples/spin
	${INSTALL_MAN} ${WRKSRC}/Man/spin.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
