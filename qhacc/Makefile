# $NetBSD: Makefile,v 1.7 2010/01/18 09:38:30 thomasklausner Exp $
#

DISTNAME=		qhacc-3.3
PKGREVISION=		1
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
