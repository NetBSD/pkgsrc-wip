# $NetBSD: Makefile,v 1.5 2007/01/04 17:02:04 shattered Exp $

DISTNAME=		tde-5.1u
PKGNAME=		tde-5.1.20
CATEGORIES=		editors
MASTER_SITES=		http://www.geocities.com/jadoxa/tde/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Thomson-Davis Editor

USE_TOOLS+=		gmake
MAKE_FILE=		makefile
BUILD_TARGET=		tde

SUBST_CLASSES+=		base
SUBST_MESSAGE.base=	Configuring to use LOCALBASE.
SUBST_STAGE.base=	post-patch
SUBST_FILES.base=	makefile
SUBST_SED.base=		-e 's,/usr/local,${PREFIX},g'

.include "../../mk/bsd.pkg.mk"
