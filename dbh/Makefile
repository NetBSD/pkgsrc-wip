# $NetBSD: Makefile,v 1.2 2003/04/04 09:10:49 bmeurer Exp $

DISTNAME=		dbh_1.0-14
PKGNAME=		dbh-1.0.14
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dbh/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://dbh.sourceforge.net/
COMMENT=		Library to create disk based Hashtables

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/src/dbh-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
