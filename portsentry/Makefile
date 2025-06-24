# $NetBSD: Makefile,v 1.21 2017/08/16 20:21:14 wiz Exp $

DISTNAME=	portsentry-2.0.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=portsentry/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/portsentry/portsentry
COMMENT=	Detects and respond to port scans against a target host in real-time
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=		-DCONFIG_FILE=\"${PKG_SYSCONFDIR}/portsentry.conf\"
CMAKE_CONFIGURE_ARGS+=		-DWRAPPER_HOSTS_DENY=\"/etc/hosts.deny\"
# ".." because this package sets PKG_SYSCONFSUBDIR
CMAKE_CONFIGURE_ARGS.SunOS+=	-DWRAPPER_HOSTS_DENY=\"${PKG_SYSCONFDIR}/../hosts.deny\"

EGDIR=		${PREFIX}/share/examples/portsentry
CONF_FILES=	${EGDIR}/portsentry.conf ${PKG_SYSCONFDIR}/portsentry.conf
CONF_FILES+=	${EGDIR}/portsentry.ignore ${PKG_SYSCONFDIR}/portsentry.ignore

MAKE_DIRS+=	${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	portsentry

INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${EGDIR}/logrotate.d
INSTALLATION_DIRS+=	${EGDIR}/systemd

SUBST_CLASSES+=		prefix
SUBST_SED.prefix+=	-e "s,/etc/portsentry,${PKG_SYSCONFDIR},"
SUBST_FILES.prefix+=	examples/portsentry.conf
SUBST_MESSAGE.prefix=	Fixing path to config file.
SUBST_STAGE.prefix=	post-build

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/portsentry.* ${DESTDIR}${EGDIR}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/../logrotate.d/portsentry ${DESTDIR}${EGDIR}/logrotate.d
	${MV} ${DESTDIR}${PREFIX}/lib/systemd/system//portsentry.service ${DESTDIR}${EGDIR}/systemd

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
