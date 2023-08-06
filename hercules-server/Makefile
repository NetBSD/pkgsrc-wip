# $NetBSD$

DISTNAME=	hercules-server-2023.07.12
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=HerculesWS/}
GITHUB_PROJECT=	Hercules
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://herc.ws/
COMMENT=	MMORPG server package
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/Hercules-${PKGVERSION_NOREV}

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	bash gmake
CONFIG_SHELL=	bash

CHECK_PORTABILITY_SKIP+=	configure

INSTALLATION_DIRS+=	bin

do-install:
	for prog in char-server login-server map-server;				\
	do										\
		${INSTALL_PROGRAM} ${WRKSRC}/$${prog} ${DESTDIR}${PREFIX}/bin/$${prog};	\
	done

.include "../../databases/mariadb106-client/buildlink3.mk"
.include "../../databases/mariadb106-server/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
