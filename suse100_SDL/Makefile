# $NetBSD: Makefile,v 1.2 2007/07/30 15:49:11 jlamwww Exp $

DISTNAME=		suse_SDL-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
DISTFILES=		SDL-1.2.8-8.${SUSE_ARCH}.rpm			\
			aalib-1.4.0-290.${SUSE_ARCH}.rpm		\
			gpm-1.20.1-309.${SUSE_ARCH}.rpm

MAINTAINER=		tonio@NetBSD.org
COMMENT=		Linux compatibility package for the SDL library

EMUL_MODULES.linux=	base slang

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
