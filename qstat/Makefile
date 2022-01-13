# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	qstat-2.17
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=multiplay/}

MAINTAINER=	shozp@directbox.com
HOMEPAGE=	https://github.com/multiplay/qstat/
COMMENT=	QStat is a command-line program that displays information about Internet game servers
LICENSE=	artistic-2.0

DEPENDS+=	autoconf-[0-9]*:../../devel/autoconf
DEPENDS+=	automake-[0-9]*:../../devel/automake
DEPENDS+=       m4-[0-9]*:../../devel/m4
DEPENDS+=       libtool-base-[0-9]*:../../devel/libtool-base
DEPENDS+=	autogen-[0-9]*:../../devel/autogen

WRKSRC=		${WRKDIR}/qstat-2.17
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS=	gmake perl automake autoconf autogen shtool m4 libtool

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/autogen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
