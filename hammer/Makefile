# $NetBSD: Makefile,v 1.2 2014/04/14 09:58:50 thomasklausner Exp $

VERSION=		1.0.0-rc3
DISTNAME=		hammer-${VERSION}
PKGNAME=		${DISTNAME:C/-rc/rc/}
DISTFILES=		v${VERSION}${EXTRACT_SUFX}
CATEGORIES=		devel
MASTER_SITES=		https://github.com/UpstandingHackers/hammer/archive/

MAINTAINER=		thequux@upstandinghackers.com
HOMEPAGE=		http://github.com/UpstandingHackers/hammer
COMMENT=		Parser combinator library in C
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=         scons-[0-9]*:../../devel/scons

USE_LANGUAGES=		c c++
DIST_SUBDIR=		hammer
EXTRACT_USING=		bsdtar

SCONS_ARGS=		--variant=opt DESTDIR=${DESTDIR} prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/scons ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && ${PREFIX}/bin/scons ${SCONS_ARGS} install

.include "../../mk/bsd.pkg.mk"
