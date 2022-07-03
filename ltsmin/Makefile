# $NetBSD$

DISTNAME=	ltsmin-v3.0.2-source
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=utwente-fmt/ltsmin/releases/download/v3.0.2/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ltsmin.utwente.nl/
COMMENT=	The LTSmin model checking toolset
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/ltsmin-3.0.2
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
DEPENDS+=	flex>=2.6.4:../../devel/flex

.include "../../mk/bsd.pkg.mk"
