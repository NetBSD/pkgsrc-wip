# $NetBSD: Makefile,v 1.3 2006/09/09 02:49:33 obache Exp $

DISTNAME=		tde-5.1s
CATEGORIES=		editors
MASTER_SITES=		http://www.geocities.com/jadoxa/tde/

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		51s1.txt
MAINTAINER=		ben@NetBSD.org
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
