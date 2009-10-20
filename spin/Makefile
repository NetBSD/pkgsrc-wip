# $NetBSD: Makefile,v 1.4 2009/10/20 12:52:48 jihbed Exp $
#

DISTNAME=	spin522
PKGNAME=	${DISTNAME:S/522//}-5.2.2
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
	cd ${WRKSRC}/Src5.2.2 && ${GMAKE}

do-install:
	cd ${WRKSRC}/Xspin5.2 && \
		${MV} xspin521.tcl xspin
	${INSTALL_PROGRAM} ${WRKSRC}/Src5.2.2/spin \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Xspin5.2/xspin \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Doc/* \
		${DESTDIR}${PREFIX}/share/doc/spin
	${INSTALL_DATA} ${WRKSRC}/Test/* \
		${DESTDIR}${PREFIX}/share/examples/spin
	${INSTALL_MAN} ${WRKSRC}/Man/spin.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
