# $NetBSD: Makefile,v 1.5 2012/11/13 22:25:38 othyro Exp $

DISTNAME=	libosmocore-1.0.1
CATEGORIES=	devel ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=osmocom/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.osmocom.org/
COMMENT=	Utility library for Software Defined Radio
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	autoconf automake autoreconf gmake pkg-config

PKGCONFIG_OVERRIDE+=	libosmocodec.pc.in
PKGCONFIG_OVERRIDE+=	libosmocoding.pc.in
PKGCONFIG_OVERRIDE+=	libosmocore.pc.in
PKGCONFIG_OVERRIDE+=	libosmoctrl.pc.in
PKGCONFIG_OVERRIDE+=	libosmogb.pc.in
PKGCONFIG_OVERRIDE+=	libosmogsm.pc.in
PKGCONFIG_OVERRIDE+=	libosmosim.pc.in
PKGCONFIG_OVERRIDE+=	libosmovty.pc.in

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ENV+=		ac_cv_prog_PYTHON=${PYTHONBIN}
# libosmocore.so: undefined reference to `__cpu_model'
CONFIGURE_ENV.NetBSD+=	osmo_cv_cc_has_builtin=false

CONFIGURE_ARGS+=	--disable-pcsc

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../devel/talloc/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
