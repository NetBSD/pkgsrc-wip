# $NetBSD: Makefile,v 1.11 2010/02/20 10:39:01 obache Exp $

META_PACKAGE=	yes

.include "Makefile.common"

PKGNAME:=	Canna-${CANNA_VERSION}

DEPENDS+=	Canna-server>=${CANNA_VERSION}:../../wip/canna-server
DEPENDS+=	Canna-dict>=${CANNA_VERSION}:../../wip/canna-dict

CANNA_MODULE=	meta-package

.include "../../mk/bsd.pkg.mk"
