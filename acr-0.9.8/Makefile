# $NetBSD: Makefile,v 1.3 2014/12/09 22:29:16 krytarowski Exp $
#

VERSION=		0.9.8
DISTNAME=		${VERSION}
PKGNAME=		acr-${VERSION}
CATEGORIES=		devel
MASTER_SITES=		https://github.com/radare/${PKGBASE}/archive/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/radare/acr
COMMENT=		Autoconf replacement
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
# Only defined the install target
NO_BUILD=		yes

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
