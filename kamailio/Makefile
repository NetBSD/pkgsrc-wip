# $NetBSD$

VERSION=	5.3.1
DISTNAME=	kamailio-${VERSION}_src
PKGNAME=	kamailio-${VERSION}
CATEGORIES=	comms
MASTER_SITES=	https://www.kamailio.org/pub/kamailio/${VERSION}/src/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.kamailio.org/
COMMENT=	SIP server
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/kamailio-${VERSION}
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake
MAKE_ENV=	include_modules="xmpp"

FAKE_NCURSES=	yes

CONF_FILES+=	share/examples/kamailio/kamailio.cfg  ${PKGSYSCONFDIR}/kamailio/kamailio.cfg
CONF_FILES+=	share/examples/kamailio/kamctlrc ${PKGSYSCONFDIR}/kamailio/kamctlrc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
