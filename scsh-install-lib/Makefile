#
# $NetBSD: Makefile,v 1.1.1.1 2005/02/15 20:54:04 airhead Exp $
#

DISTNAME=		scsh-install-lib-1.2.0
CATEGORIES=		wip devel
MASTER_SITES=		http://lamp.epfl.ch/~schinz/scsh_packages/

MAINTAINER=		airhead@users.sf.net
HOMEPAGE=		http://lamp.epfl.ch/~schinz/scsh_packages/
COMMENT=		SCSH installation library for third-party libraries

BUILD_DEPENDS+=		scsh>=0.6:../../shells/scsh

NO_BUILD=		yes

do-install:
	cd ${WRKSRC}; \
	./install.scm --bindir ${PREFIX}/bin --prefix ${PREFIX} --verbose --layout fhs

.include "../../mk/bsd.pkg.mk"
