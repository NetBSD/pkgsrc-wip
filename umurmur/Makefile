# $NetBSD: Makefile,v 1.6 2015/06/13 11:48:57 fhajny Exp $
#

DISTNAME=	umurmur-0.2.16
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=umurmur/}

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://umurmur.googlecode.com/
COMMENT=	Mumble (murmur) server for embedded systems
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	gmake

LDFLAGS.SunOS+=	-lresolv -lsocket -lnsl

INSTALLATION_DIRS=	sbin share/examples/umurmur

EGDIR=		${PREFIX}/share/examples/umurmur
CONF_FILES+=	${EGDIR}/umurmur.conf ${PKG_SYSCONFDIR}/umurmur.conf

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_FILES.path=	src/conf.c src/config.h.in umurmur.conf.example
SUBST_SED.path=		-e 's,/etc/umurmur,${PKG_SYSCONFDIR}/umurmur,g'
SUBST_VARS.path=	PKG_SYSCONFDIR

MAKE_DIRS+=	${PKG_SYSCONFDIR}/umurmur
RCD_SCRIPTS=	umurmur

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/umurmurd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/umurmur.conf.example \
		${DESTDIR}${EGDIR}/umurmur.conf

.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../security/mbedtls1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
