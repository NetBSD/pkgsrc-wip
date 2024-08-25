# $NetBSD$

DISTNAME=	openwsman-2.6.11
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Openwsman/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Openwsman/openwsman/
COMMENT=	WS-Management for all
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_PYTHON3:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_PYTHON:BOOL=OFF
CMAKE_CONFIGURE_ARGS+=	-DLIB:PATH=lib

PKGCONFIG_OVERRIDE+=	openwsman++.pc.in
PKGCONFIG_OVERRIDE+=	openwsman-server.pc.in
PKGCONFIG_OVERRIDE+=	openwsman.pc.in

REPLACE_RUBY+=	examples/winrs.rb

INSTALLATION_DIRS+=	share/examples/openwsman/pam.d

EGDIR=		share/examples/openwsman
OWN_DIRS+=	${PKG_SYSCONFDIR}/openwsman
CONF_FILES+=	${PREFIX}/${EGDIR}/openwsman.conf ${PKG_SYSCONFDIR}/openwsman/openwsman.conf
CONF_FILES+=	${PREFIX}/${EGDIR}/openwsman_client.conf ${PKG_SYSCONFDIR}/openwsman/openwsman_client.conf
CONF_FILES+=	${PREFIX}/${EGDIR}/owsmangencert.sh ${PKG_SYSCONFDIR}/openwsman/owsmangencert.sh
CONF_FILES+=	${PREFIX}/${EGDIR}/ssleay.cnf ${PKG_SYSCONFDIR}/openwsman/ssleay.cnf

post-install:
	cd ${DESTDIR}${PREFIX}/etc/openwsman && \
		${MV} openwsman.conf openwsman_client.conf owsmangencert.sh ssleay.cnf \
			${DESTDIR}${PREFIX}/share/examples/openwsman
	${MV} ${DESTDIR}${PREFIX}/etc/pam.d/openwsman/ \
			${DESTDIR}${PREFIX}/share/examples/openwsman/pam.d

.include "../../wip/sblim-sfcc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
