# $NetBSD: Makefile,v 1.3 2003/06/12 05:15:34 xtraeme Exp $
#

DISTNAME=	jabberd-2.0.0-a4
PKGNAME=	${DISTNAME:C/d-2.0.0-a/d2-2.0.0rc/}
CATEGORIES=	chat
MASTER_SITES=	http://www.jabberstudio.org/files/jabberd2/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.jabberstudio.org/
COMMENT=	Instant messaging server ( version 2 )

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

RCD_SCRIPTS=		jabberd

EGDIR=			${PREFIX}/share/examples/jabberd

CONF_FILES=	${EGDIR}/c2s.xml ${PKG_SYSCONFDIR}/jabberd/c2s.xml
CONF_FILES+=	${EGDIR}/resolver.xml ${PKG_SYSCONFDIR}/jabberd/resolver.xml
CONF_FILES+=    ${EGDIR}/router.xml ${PKG_SYSCONFDIR}/jabberd/router.xml
CONF_FILES+=	${EGDIR}/s2s.xml ${PKG_SYSCONFDIR}/jabberd/s2s.xml
CONF_FILES+=	${EGDIR}/sm.xml ${PKG_SYSCONFDIR}/jabberd/sm.xml

SUPPORT_FILES+= ${EGDIR}/jabberd.cfg ${PKG_SYSCONFDIR}/jabberd/jabberd.cfg

OWN_DIRS=		/var/log/jabberd
OWN_DIRS+=		/var/db/jabberd

post-extract:
	${MV} ${WRKSRC}/etc/jabberd.cfg.dist.in ${WRKSRC}/etc/jabberd.cfg.in
	${MV} ${WRKSRC}/etc/c2s.xml.dist.in ${WRKSRC}/etc/c2s.xml.in
	${MV} ${WRKSRC}/etc/router.xml.dist.in ${WRKSRC}/etc/router.xml.in 
	${MV} ${WRKSRC}/etc/resolver.xml.dist.in ${WRKSRC}/etc/resolver.xml.in
	${MV} ${WRKSRC}/etc/s2s.xml.dist.in ${WRKSRC}/etc/s2s.xml.in
	${MV} ${WRKSRC}/etc/sm.xml.dist.in ${WRKSRC}/etc/sm.xml.in

pre-configure:
	${SED} 	\
		-e "s|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g" \
              	< ${WRKSRC}/etc/jabberd.cfg.in > ${WRKSRC}/etc/jabberd.cfg
	
	${SED}  \
                -e "s|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g" \
		-e "s|@@LOGDIR@@|/var/log/jabberd|g " \
		-e "s|@@BINDIR@@|${PREFIX}/bin|g " \
                < ${WRKSRC}/etc/c2s.xml.in > ${WRKSRC}/etc/c2s.xml
	
	${SED}  \
                -e "s|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g" \
                -e "s|@@LOGDIR@@|/var/log/jabberd|g " \
		< ${WRKSRC}/etc/resolver.xml.in > ${WRKSRC}/etc/resolver.xml
        
	${SED}  \
                -e "s|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g" \
                -e "s|@@LOGDIR@@|/var/log/jabberd|g " \
		< ${WRKSRC}/etc/router.xml.in > ${WRKSRC}/etc/router.xml
        
	${SED}  \
                -e "s|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g" \
                -e "s|@@LOGDIR@@|/var/log/jabberd|g " \
		< ${WRKSRC}/etc/s2s.xml.in > ${WRKSRC}/etc/s2s.xml
        
	${SED}  \
                -e "s|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g" \
                -e "s|@@LOGDIR@@|/var/log/jabberd|g " \
		-e "s|@@DBDIR@@|/var/db/jabberd|g" \
		< ${WRKSRC}/etc/sm.xml.in > ${WRKSRC}/etc/sm.xml

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/*.cfg ${EGDIR}
	for f in ${WRKSRC}/etc/*.xml; do \
		${INSTALL_DATA} $$f ${EGDIR}; \
	done

.include "../../converters/libiconv/buildlink2.mk"
.include "../../databases/db4/buildlink2.mk"
.include "../../databases/openldap/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../security/cyrus-sasl2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
