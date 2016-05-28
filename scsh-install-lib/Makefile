#
# $NetBSD: Makefile,v 1.3 2012/10/07 16:22:54 asau Exp $
#

DISTNAME=		scsh-install-lib-1.2.0
CATEGORIES=		devel
MASTER_SITES=		http://lamp.epfl.ch/~schinz/scsh_packages/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://lamp.epfl.ch/~schinz/scsh_packages/
COMMENT=		SCSH installation library for third-party libraries

BUILD_DEPENDS+=		scsh>=0.6:../../shells/scsh


NO_BUILD=		yes

do-install:
	cd ${WRKSRC}; \
	./install.scm --bindir ${PREFIX}/bin --prefix ${PREFIX} --verbose --layout fhs

.include "../../mk/bsd.pkg.mk"
