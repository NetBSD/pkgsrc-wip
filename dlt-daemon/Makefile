# $NetBSD$

GITHUB_PROJECT=	dlt-daemon
VERSION=	2.18.3
PKGNAME=	${GITHUB_PROJECT}-${VERSION}
DISTNAME=	v${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=GENIVI/}
GITHUB_TAG=	${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/GENIVI/dlt-daemon/
COMMENT=	GENIVI Diagnostic Log and Trace
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}/dlt-daemon-${VERSION}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	automotive-dlt-c++.pc.in
PKGCONFIG_OVERRIDE+=	automotive-dlt.pc.in

ONLY_FOR_PLATFORM=	Linux-*-*

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONFS=		dlt.conf dlt_gateway.conf

.for f in ${CONFS}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 share/examples/${PKGBASE}

OWN_DIRS+=	${PKG_SYSCONFDIR}/xbps.d

post-install:
	${MKDIR} ${DESTDIR}${EGDIR} &&\
        for f in ${CONFS}; do \
          ${MV} ${DESTDIR}${PREFIX}/etc/$${f} ${DESTDIR}${EGDIR}; \
        done

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
