# $NetBSD$

GITHUB_PROJECT=	tintin
DISTNAME=	tintin-2.02.20
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=scandum/}
GITHUB_RELEASE=	2.02.20

MAINTAINER=	kludev@gmail.com
HOMEPAGE=	https://github.com/scandum/tintin/
COMMENT=	Free Mud client for Android, iOS, Linux, Mac OS X and Windows
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/tt/src
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
