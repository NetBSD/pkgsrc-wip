# $NetBSD: Makefile,v 1.5 2011/03/13 23:38:33 pettai Exp $
#

DISTNAME=	shibboleth-sp-${PKGVERSION}
PKGVERSION=	2.4.2
CATEGORIES=	www
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/shibboleth/cppsp/latest/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://shibboleth.internet2.edu/
COMMENT=	Shibboleth2 Service Provider (Apache module)
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=	VARBASE

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-xmltooling=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

WRKSRC=		${WRKDIR}/shibboleth-2.4.2
EGDIR=		${PREFIX}/share/examples/shibboleth

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

RCD_SCRIPTS=	shibd

APACHE_MODULE=	YES

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/configs/Makefile.in
SUBST_STAGE.paths=	post-patch
SUBST_SED.paths=	-e 's,@EGDIR@,${EGDIR},'

CONF_FILES=	${EGDIR}/console.logger \
			${PKG_SYSCONFDIR}/shibboleth/console.logger
CONF_FILES+=	${EGDIR}/native.logger \
			${PKG_SYSCONFDIR}/shibboleth/native.logger
CONF_FILES+=	${EGDIR}/shibd.logger \
			${PKG_SYSCONFDIR}/shibboleth/shibd.logger
CONF_FILES+=	${EGDIR}/syslog.logger \
			${PKG_SYSCONFDIR}/shibboleth/syslog.logger
CONF_FILES+=	${EGDIR}/shibboleth2.xml \
			${PKG_SYSCONFDIR}/shibboleth/shibboleth2.xml
CONF_FILES+=	${EGDIR}/attribute-map.xml \
			${PKG_SYSCONFDIR}/shibboleth/attribute-map.xml
CONF_FILES+=	${EGDIR}/attribute-policy.xml \
			${PKG_SYSCONFDIR}/shibboleth/attribute-policy.xml
CONF_FILES+=	${EGDIR}/protocols.xml \
			${PKG_SYSCONFDIR}/shibboleth/protocols.xml
CONF_FILES+=	${EGDIR}/security-policy.xml \
			${PKG_SYSCONFDIR}/shibboleth/security-policy.xml
CONF_FILES+=	${EGDIR}/accessError.html \
			${PKG_SYSCONFDIR}/shibboleth/accessError.html
CONF_FILES+=	${EGDIR}/sessionError.html \
			${PKG_SYSCONFDIR}/shibboleth/sessionError.html
CONF_FILES+=	${EGDIR}/metadataError.html \
			${PKG_SYSCONFDIR}/shibboleth/metadataError.html
CONF_FILES+=	${EGDIR}/bindingTemplate.html \
			${PKG_SYSCONFDIR}/shibboleth/bindingTemplate.html
CONF_FILES+=	${EGDIR}/discoveryTemplate.html \
			${PKG_SYSCONFDIR}/shibboleth/discoveryTemplate.html
CONF_FILES+=	${EGDIR}/postTemplate.html \
			${PKG_SYSCONFDIR}/shibboleth/postTemplate.html
CONF_FILES+=	${EGDIR}/localLogout.html \
			${PKG_SYSCONFDIR}/shibboleth/localLogout.html
CONF_FILES+=	${EGDIR}/globalLogout.html \
			${PKG_SYSCONFDIR}/shibboleth/globalLogout.html
CONF_FILES+=	${EGDIR}/partialLogout.html \
			${PKG_SYSCONFDIR}/shibboleth/partialLogout.html
CONF_FILES+=	${EGDIR}/sslError.html \
			${PKG_SYSCONFDIR}/shibboleth/sslError.html

INSTALLATION_DIRS+=	${PREFIX}/bin ${PREFIX}/sbin
INSTALLATION_DIRS+=	${PREFIX}/include/shibsp/attribute/resolver
INSTALLATION_DIRS+=	${PREFIX}/include/shibsp/binding
INSTALLATION_DIRS+=	${PREFIX}/include/shibsp/handler
INSTALLATION_DIRS+=	${PREFIX}/include/shibsp/lite
INSTALLATION_DIRS+=     ${PREFIX}/include/shibsp/metadata
INSTALLATION_DIRS+=	${PREFIX}/include/shibsp/remoting
INSTALLATION_DIRS+=	${PREFIX}/include/shibsp/security
INSTALLATION_DIRS+=	${PREFIX}/include/shibsp/util
INSTALLATION_DIRS+=	${PREFIX}/share/doc/shibboleth-${PKGVERSION}
INSTALLATION_DIRS+=     ${PREFIX}/share/doc/shibboleth-${PKGVERSION}/api
INSTALLATION_DIRS+=     ${PREFIX}/share/xml/shibboleth
INSTALLATION_DIRS+=     ${PREFIX}/lib/shibboleth
INSTALLATION_DIRS+=	${EGDIR} ${PKG_SYSCONFDIR}/shibboleth
INSTALLATION_DIRS+=	${VARBASE}/log/shibboleth

post-install:
	${INSTALL} ${WRKSRC}/configs/keygen.sh \
		${DESTDIR}${PREFIX}/sbin/shib-keygen.sh
	${INSTALL} ${WRKSRC}/configs/metagen.sh \
		${DESTDIR}${PREFIX}/bin/shib-metagen.sh

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/log4shib/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../textproc/xmltooling/buildlink3.mk"
.include "../../security/opensaml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
