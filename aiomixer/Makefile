# $NetBSD$

DISTNAME=	aiomixer-0.9.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=ensra/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/ensra/aiomixer
COMMENT=	NetBSD audio mixer
LICENSE=	2-clause-bsd

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

ONLY_FOR_PLATFORM=	NetBSD-*-*

BUILDLINK_API_DEPENDS.cdk+=	cdk>=5.0.0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aiomixer ${DESTDIR}${PREFIX}/bin/aiomixer
	${INSTALL_DATA} ${WRKSRC}/aiomixer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/aiomixer.1

.include "../../devel/cdk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
