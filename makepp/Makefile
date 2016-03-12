# $NetBSD: Makefile,v 1.1 2014/01/19 16:40:23 keckhardt Exp $

DISTNAME=	makepp-2.0.98.4
CATEGORIES=	devel
MASTER_SITES=	http://sourceforge.net/projects/makepp/files/2.1/snapshots/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://makepp.sourceforge.net/
COMMENT=	Compatible and reliable make replacement written in Perl
LICENSE=	artistic

USE_TOOLS+=	perl

TEST_TARGET=	test

do-configure:
	cd ${WRKSRC} && ./configure --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
