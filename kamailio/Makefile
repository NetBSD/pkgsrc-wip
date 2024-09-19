# $NetBSD$

VERSION=	5.3.3
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

# Upstream says that python is required for the "python module", but
# installs a file with a python #! line, so depend on it always for now
# Upstream does not explain versions.  Prepare to disallow 27.
#PYTHON_VERSIONS_INCOMPATIBLE=	27

do-configure:
	cd ${WRKSRC} && ${GMAKE} cfg include_modules="xmpp"

REPLACE_PYTHON+=	utils/kamctl/dbtextdb/dbtextdb.py

# Brute-force move the config files to the example directory, because
# it's easier than teaching the kamailio build system the pkgsrc way
# of config files.
post-install:
	mkdir -p ${DESTDIR}/${PREFIX}/share/examples/kamailio
	mv ${DESTDIR}/${PKG_SYSCONFDIR}/kamailio/kamailio.cfg ${DESTDIR}/${PREFIX}/share/examples/kamailio/kamailio.cfg
	mv ${DESTDIR}/${PKG_SYSCONFDIR}/kamailio/kamctlrc ${DESTDIR}/${PREFIX}/share/examples/kamailio/kamctlrc

CONF_FILES+=	share/examples/kamailio/kamailio.cfg  ${PKG_SYSCONFDIR}/kamailio/kamailio.cfg
CONF_FILES+=	share/examples/kamailio/kamctlrc ${PKG_SYSCONFDIR}/kamailio/kamctlrc

FAKE_NCURSES=	yes
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
