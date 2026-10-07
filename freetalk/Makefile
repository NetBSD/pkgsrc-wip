# $NetBSD$

DISTNAME=	freetalk-4.2
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
	${RUN} cd ${WRKSRC} && ./bootstrap

# This is needed on NetBSD, probably on !Linux, but upstream
# Makefile.am does not seem to have a hook for extra libs.
# Reported to freetalk-dev@gnu.org 20261007.
LDLFLAGS+=	"-largp"

.include "../../chat/loudmouth/buildlink3.mk"
.include "../../devel/argp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/guile30/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
