# $NetBSD: Makefile,v 1.30 2013/02/06 19:31:04 jperkin Exp $
#

DISTNAME=	p0f-3.09b
CATEGORIES=	security net
MASTER_SITES=	https://lcamtuf.coredump.cx/p0f3/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lcamtuf.coredump.cx/p0f.shtml
COMMENT=	Passive OS fingerprinting tool
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	bash

PKG_SYSCONFSUBDIR=	p0f

MAKE_ENV+=	LIBPCAP_PREFIX=${BUILDLINK_PREFIX.libpcap}

REPLACE_BASH+=	build.sh

CONF_FILES+=	${PREFIX}/share/examples/p0f/p0f.fp ${PKG_SYSCONFDIR}/p0f.fp

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	config.h
SUBST_SED.paths=	-e "/FP_FILE/s|p0f.fp|${PKG_SYSCONFDIR}/p0f.fp|g"
SUBST_MESSAGE.paths=	Fixing paths

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/p0f share/examples/p0f

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p0f ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/p0f/p0f.README
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${DESTDIR}${PREFIX}/share/examples/p0f

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
