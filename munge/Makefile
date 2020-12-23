# $NetBSD: Makefile,v 1.23 2020/01/18 21:50:41 jperkin Exp $

DISTNAME=	munge-0.5.14
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=dun/}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://dun.github.io/munge/
COMMENT=	Authentication service for creating and validating credentials
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
INSTALLATION_DIRS+=	lib/pkgconfig

OWN_DIRS=	${VARBASE}/lib/munge
OWN_DIRS+=	${VARBASE}/log/munge
OWN_DIRS+=	${VARBASE}/run/munge
OWN_DIRS+=	etc/munge

BUILD_DEFS+=	VARBASE

RCD_SCRIPTS+=	munge

SUBST_CLASSES+=		init
SUBST_STAGE.init=	pre-configure
SUBST_FILES.init=	src/etc/munge.sysvinit.init.in
SUBST_SED.init=		-e 's|USER="munge"|USER="daemon"|g'
SUBST_SED.init+=	-e 's|GROUP="munge"|GROUP="daemon"|g'

SUBST_CLASSES+=		systemd
SUBST_STAGE.systemd=	pre-configure
SUBST_FILES.systemd=	src/etc/munge.systemd.service.in
SUBST_SED.systemd=	-e 's|User=munge|User=daemon|g'
SUBST_SED.systemd+=	-e 's|Group=munge|Group=daemon|g'

EGDIR=			${PREFIX}/share/examples/munge
CONF_FILES=		${EGDIR}/munge.systemd.sysconfig ${PKG_SYSCONFDIR}/sysconfig/munge
#CONF_FILES=		etc/logrotate.d/munge

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
