# $NetBSD: Makefile,v 1.8 2012/10/03 21:26:15 asau Exp $
#

DISTNAME=	or1ksim-0.2.0rc3
PKGREVISION=	1
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
	mv ${WRKSRC}/sim.cfg ${WRKSRC}/or1ksim.cfg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/or1ksim ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/or1ksim.cfg ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/virtex.tim ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.gdb ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
