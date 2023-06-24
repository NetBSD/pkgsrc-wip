# $NetBSD: Makefile,v 1.5 2014/04/14 11:41:58 obache Exp $

VERSION=		1.0.0-rc3
DISTNAME=		hammer-${VERSION}
PKGNAME=		${DISTNAME:C/-rc/rc/}
CATEGORIES=		devel
MASTER_SITES=		-https://github.com/UpstandingHackers/hammer/archive/v${VERSION}${EXTRACT_SUFX}

MAINTAINER=		thequux@upstandinghackers.com
HOMEPAGE=		https://github.com/UpstandingHackers/hammer
COMMENT=		Parser combinator library in C
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		scons-[0-9]*:../../devel/scons

USE_LANGUAGES=		c c++
EXTRACT_USING=		bsdtar
PKGCONFIG_OVERRIDE=	libhammer.pc.in

SCONS_ARGS=		--variant=opt DESTDIR=${DESTDIR} prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/scons ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && ${PREFIX}/bin/scons ${SCONS_ARGS} install

.include "../../mk/bsd.pkg.mk"
