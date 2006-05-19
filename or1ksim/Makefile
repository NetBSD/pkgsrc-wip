# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:28 ykomatsu Exp $
#

DISTNAME=	or1ksim-0.2.0rc3
CATEGORIES=	emulators
MASTER_SITES=	http://www.opencores.org/projects.cgi/web/or1k/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opencores.org/projects.cgi/web/or1k/architectural_simulator
COMMENT=	OpenRISC 1000 (OR1K) architecture simulator

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-execution=simple
INSTALLATION_DIRS=	bin share/examples/or1ksim share/doc/or1ksim

USE_GNU_READLINE=	yes # uses rl_event_hook

post-build:
	${MV} ${WRKSRC}/sim.cfg ${WRKSRC}/or1ksim.cfg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/or1ksim ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/or1ksim.cfg ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/virtex.tim ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.gdb ${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
