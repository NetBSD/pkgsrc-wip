# $NetBSD: Makefile,v 1.1.1.1 2003/04/03 07:59:18 bmeurer Exp $

DISTNAME=		dbh_1.0-14
PKGNAME=		dbh-1.0.14
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dbh/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://dbh.sourceforge.net/
COMMENT=		Library to create disk based Hashtables

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
