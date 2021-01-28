# $NetBSD$

VERSION=		4.2.11
DISTNAME=		${VERSION}
PKGNAME=		exabgp4-${VERSION}
PKGREVISION=		1
EGG_NAME=		exabgp-${VERSION}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=Exa-Networks/exabgp/archive/}
DIST_SUBDIR=		exabgp

MAINTAINER=		jorn.dejong@uninett.no
HOMEPAGE=		https://github.com/Exa-Networks/exabgp/
COMMENT=		Userspace BGP daemon written in python
LICENSE=		modified-bsd
CONFLICTS=		exabgp-[0-9]* # the exabgp3 package is simply called exabgp

WRKSRC=			${WRKDIR}/exabgp-${VERSION}

# Unclear if this is needed;
# perl is used in two example scripts,
# which need their shebang fixed,
# but is not needed to build or to run the software
#USE_TOOLS+=		perl:run

#PYTHON_VERSIONED_DEPENDENCIES+=	setuptools
BUILD_DEPENDS+=		${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

REPLACE_PERL+=		etc/exabgp/examples/dynamic-1.pl
REPLACE_PERL+=		etc/exabgp/examples/watchdog-1.pl

REPLACE_PYTHON+=	etc/exabgp/examples/api-add-remove.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-announce.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-announcement.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-api.nothing.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-api.receive.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-attributes-vpn.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-attributes.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-broken-flow.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-check.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-eor.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-fast.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-flow.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-manual-eor.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-multi-neighbor.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-multisession.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-nexthop-self.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-nexthop.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-no-respawn-1.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-no-respawn-2.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-notification.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-open.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-reload.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-teardown.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-vpls.run
REPLACE_PYTHON+=	etc/exabgp/examples/api-vpnv4.run
REPLACE_PYTHON+=	etc/exabgp/examples/stderr-1.py
REPLACE_PYTHON+=	etc/exabgp/examples/syslog-1.py
REPLACE_PYTHON+=	etc/exabgp/examples/watchdog.run

PYTHON_VERSIONS_ACCEPTED=	39 38 37 36

USE_LANGUAGES=		# none

RCD_SCRIPTS+=		exabgp

CONF_FILES+=		${PREFIX}/share/examples/exabgp/exabgp.env ${PREFIX}/etc/exabgp/exabgp.env

INSTALLATION_DIRS+=	share/exabgp share/examples/exabgp bin etc/exabgp
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

FILES_SUBST+=		PYTHONBIN=${PYTHONBIN}

post-patch:
	${SED} -e s,/etc/,${PREFIX}/etc/, ${WRKSRC}/doc/man/exabgp.1 > ${WRKSRC}/doc/man/exabgp.1.sed
	${CP} ${WRKSRC}/doc/man/exabgp.1.sed ${WRKSRC}/doc/man/exabgp.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/exabgp.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/exabgp.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${CP} ${FILESDIR}/exabgp.env ${DESTDIR}${PREFIX}/share/examples/exabgp/

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
