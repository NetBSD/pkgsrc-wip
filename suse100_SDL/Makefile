# $NetBSD: Makefile,v 1.1.1.1 2006/10/08 01:12:26 thomasklausner Exp $

DISTNAME=		suse_SDL-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the SDL library

DEPENDS+=		suse_base-${SUSE_VERSION}{,nb*}:../../emulators/suse100_base
DEPENDS+=		suse_slang-${SUSE_VERSION}{,nb*}:../../emulators/suse100_slang

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../mk/bsd.prefs.mk"

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
