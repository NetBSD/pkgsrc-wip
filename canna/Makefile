# $NetBSD: Makefile,v 1.1.1.1 2011/01/02 08:49:59 makoto Exp $

META_PACKAGE=	yes

.include "Makefile.common"

PKGNAME:=	Canna-${CANNA_VERSION}

DEPENDS+=	Canna-server>=${CANNA_VERSION}:../../wip/canna-server
DEPENDS+=	Canna-dict>=${CANNA_VERSION}:../../wip/canna-dict

CANNA_MODULE=	meta-package

.include "../../mk/bsd.pkg.mk"
