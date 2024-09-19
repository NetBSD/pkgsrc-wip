# $NetBSD$

DISTNAME=	freetalk-4.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNU:=freetalk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/freetalk/
COMMENT=	Console based Jabber client
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake makeinfo pkg-config
INFO_FILES=	yes

CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}

USE_LANGUAGES=	c c++

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

.include "../../chat/loudmouth/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
