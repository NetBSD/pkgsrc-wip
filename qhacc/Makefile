# $NetBSD: Makefile,v 1.9 2012/10/07 14:53:42 asau Exp $
#

DISTNAME=		qhacc-3.3
PKGREVISION=		2
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=qhacc/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://qhacc.sourceforge.net/
COMMENT=		The Q Home Accountant for bookkeeping


USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_TOOLS=		gmake

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/qhacc
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/qhacc

INSTALLATION_DIRS+=	share/examples/qhacc/easysetup

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/easysetup/[a-t]* ${PREFIX}/share/examples/qhacc/easysetup

.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
