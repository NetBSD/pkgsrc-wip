# $NetBSD: Makefile,v 1.1.1.1 2004/02/28 17:43:28 xtraeme Exp $
#

DISTNAME=	ladspa_sdk_1.12
PKGNAME=	${DISTNAME:S/_sdk_/-/}
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.ladspa.org/
COMMENT=	Linux Audio Developers Simple Plugin API

WRKSRC=		${WRKDIR}/ladspa_sdk/src
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

MAKEFILE=	makefile

.include "../../mk/bsd.pkg.mk"
