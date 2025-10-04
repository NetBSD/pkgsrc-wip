# $NetBSD$
# Local variables:
# coding: unix
# End:
DISTNAME=		suricata-8.0.1
PKGREVISION=		1
CATEGORIES=		net security
MASTER_SITES=		https://www.openinfosecfoundation.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://suricata.io/
COMMENT=		Fast open source network analysis and threat detection software
LICENSE=		gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

USE_LANGUAGES=		c c++

LIBS.NetBSD+=		 -lm

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} --localstatedir=${VARBASE}
EGDIR=                  ${PREFIX}/share/examples/suricata
INSTALLATION_DIRS+=     ${EGDIR}
INSTALL_MAKE_FLAGS=     ${MAKE_FLAGS} sysconfdir=${EGDIR}

PKG_OPTIONS_VAR=	PKG_OPTIONS.suricata
PKG_SUPPORTED_OPTIONS=	enable-unittests enable-debug enable-profiling
#PKG_SUGGESTED_OPTIONS=

RCD_SCRIPTS+=		suricata

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Menable-unittests)
CONFIGURE_ARGS+=	--enable-unittests
.endif

.if !empty(PKG_OPTIONS:Menable-debug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Menable-profiling)
CONFIGURE_ARGS+=	--enable-profiling
.endif

#
# Generate and place some initial configuration files into EGDIR!
# 
post-install:
	cd ${WRKSRC} \
	&& env ${INSTALL_ENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} install-conf \
			&& ${MV} ${DESTDIR}${PREFIX}/etc/suricata/* ${DESTDIR}${EGDIR} \
				&& find ${DESTDIR}${EGDIR} -type f -print | sort \
					> ${WRKDIR}/PLIST_DYNAMIC
# plist gen helper
PLIST.SRC+=	${WRKDIR}/PLIST_DYNAMIC

.include "../../devel/pcre2/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"

# not found by configure for some reason:
.include "../../lang/libunwind/buildlink3.mk"

.include "../../archivers/lz4/buildlink3.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
