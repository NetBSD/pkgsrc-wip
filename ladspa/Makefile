# $NetBSD: Makefile,v 1.2 2004/05/07 01:57:59 xtraeme Exp $
#

DISTNAME=	ladspa_sdk_1.12
PKGNAME=	${DISTNAME:S/_sdk_/-/}
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ladspa.org/
COMMENT=	Linux Audio Developers Simple Plugin API

WRKSRC=		${WRKDIR}/ladspa_sdk/src
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

MAKEFILE=	makefile

.include "../../mk/bsd.pkg.mk"
