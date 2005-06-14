# $NetBSD: Makefile,v 1.1.1.1 2005/06/14 08:46:05 ghen Exp $

DISTNAME=		distcc-2.18.2
PKGNAME=		${DISTNAME:S/-/-gtk-/}
CATEGORIES=		devel
MASTER_SITES=		http://distcc.samba.org/ftp/distcc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		geert.hendrickx@ua.ac.be
HOMEPAGE=		http://distcc.samba.org/
COMMENT=		Graphical monitor for distcc, the distributed C/C++ compiler

DEPENDS+=		distcc>=2.18.2:../../devel/distcc

USE_TOOLS+=		gmake
USE_PKGINSTALL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-rfc2553
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS=		--with-gtk

BUILD_TARGET=		distccmon-gnome

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/distccmon-gnome ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/distcc
	${INSTALL_DATA} ${WRKSRC}/gnome/distccmon-gnome-icon.png ${PREFIX}/share/distcc
	${INSTALL_DATA} ${WRKSRC}/gnome/distccmon-gnome.desktop ${PREFIX}/share/distcc

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
