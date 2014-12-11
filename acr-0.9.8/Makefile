# $NetBSD: Makefile,v 1.4 2014/12/11 20:01:58 krytarowski Exp $
#

VERSION=		0.9.8
DISTNAME=		${VERSION}
PKGNAME=		acr-${VERSION}
CATEGORIES=		devel
MASTER_SITES=		https://github.com/radare/${PKGBASE}/archive/
EXTRACT_SUFX=		.zip
DIST_SUBDIR=		${PKGBASE}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/radare/acr
COMMENT=		Autoconf replacement
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
# Only defined the install target
NO_BUILD=		yes

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
