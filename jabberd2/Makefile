# $NetBSD: Makefile,v 1.7 2003/06/12 11:27:29 xtraeme Exp $
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

RCD_SCRIPTS=		jabberd
PKG_SYSCONFSUBDIR=	jabberd

EGDIR=			${PREFIX}/share/examples/jabberd
SUPPORT_FILES+=         ${EGDIR}/jabberd.cfg ${PKG_SYSCONFDIR}/jabberd.cfg

FILES=			c2s resolver router s2s sm

.for f in ${FILES}
CONF_FILES+=		${EGDIR}/${f}.xml ${PKG_SYSCONFDIR}/${f}.xml
.endfor

OWN_DIRS=		/var/log/jabberd
OWN_DIRS+=		/var/db/jabberd

post-extract:

.for f in ${FILES}
	${MV} ${WRKSRC}/etc/${f}.xml.dist.in ${WRKSRC}/etc/${f}.xml.in
.endfor
	${MV} ${WRKSRC}/etc/jabberd.cfg.dist.in ${WRKSRC}/etc/jabberd.cfg.in

pre-configure:

.for f in ${FILES}
	${SED}  \
                -e "s|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g" \
		-e "s|@@LOGDIR@@|/var/log/jabberd|g " \
		-e "s|@@BINDIR@@|${PREFIX}/bin|g " \
		-e "s|@@DBDIR@@|/var/db/jabberd|g " \
                < ${WRKSRC}/etc/${f}.xml.in > ${WRKSRC}/etc/${f}.xml
.endfor	

.for f in ${WRKSRC}/etc/jabberd.cfg.in 
	${SED}  \
		-e "s|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g" \
		< ${WRKSRC}/etc/jabberd.cfg.in > ${WRKSRC}/etc/jabberd.cfg
.endfor

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
