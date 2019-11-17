# $NetBSD$

GITHUB_PROJECT=	guest-oslogin
GITHUB_TAG=	4d53cc0ffdb
DISTNAME=	guest-oslogin-20191023
CATEGORIES=	wip sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=GoogleCloudPlatform/}
EXTRACT_SUFX=	.zip

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/GoogleCloudPlatform/guest-oslogin/
COMMENT=	OS Login Guest Environment for Google Compute Engine
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/guest-oslogin-4d53cc0ffdb5f11c3a29bc84db86b41cd9f87cb7
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake

.include "../../www/curl/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
