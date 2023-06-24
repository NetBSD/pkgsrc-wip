# $NetBSD: Makefile,v 1.1 2013/06/02 22:30:23 thomasklausner Exp $

DISTNAME=	safekeep-1.4.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=safekeep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://safekeep.sourceforge.net/
COMMENT=	Centralized and easy to use backup application
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
BUILD_TARGET=	build

# XXX: sysconfdir not respected by safekeep script
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	sysconfdir=${EGDIR}
MAKE_FLAGS+=	mandir=${PKGMANDIR}

REPLACE_PYTHON=	safekeep

EGDIR=		share/examples/safekeep

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
