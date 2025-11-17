# $NetBSD: Makefile,v 1.3 2014/02/11 21:04:08 noud4 Exp $
#

DISTNAME=		fala_0.1-1
PKGNAME=		fala-0.1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fala/}

MAINTAINER=		noud4@users.sourceforge.net
HOMEPAGE=		https://fala.sourceforge.net/
COMMENT=		Simple text reader
LICENSE=		public-domain

WRKSRC=			${WRKDIR}/fala
USE_LANGUAGES=		# none

REPLACE_PYTHON=		check.py src/fala.py

.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
