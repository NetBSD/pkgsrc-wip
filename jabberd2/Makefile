# $NetBSD: Makefile,v 1.10 2003/06/14 04:59:31 xtraeme Exp $
#

DISTNAME=		jabberd-2.0.0-a4
PKGNAME=		${DISTNAME:S/d-2.0.0-a/d2-2.0.0alpha/}
CATEGORIES=		chat
MASTER_SITES=		http://www.jabberstudio.org/files/jabberd2/

MAINTAINER=		jrp@hispabsd.org
HOMEPAGE=		http://www.jabberstudio.org/
COMMENT=		Instant messaging server ( version 2 )

CONFLICTS=		jabberd-[0-9]*:../../wip/jabberd

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

RCD_SCRIPTS=		jabberd
PKG_SYSCONFSUBDIR=	jabberd

EGDIR=			${PREFIX}/share/examples/jabberd
SUPPORT_FILES=          ${EGDIR}/jabberd.cfg ${PKG_SYSCONFDIR}/jabberd.cfg

FILES=			c2s.xml resolver.xml router.xml s2s.xml sm.xml

.for f in ${FILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

OWN_DIRS=		/var/log/jabberd
OWN_DIRS+=		/var/db/jabberd

post-extract:

.for f in ${FILES}
	${MV} ${WRKSRC}/etc/${f}.dist.in ${WRKSRC}/etc/${f}.in
.endfor
	${MV} ${WRKSRC}/etc/jabberd.cfg.dist.in ${WRKSRC}/etc/jabberd.cfg.in
.undef f

pre-configure:

.for f in ${FILES}
	${SED}  \
		-e "s|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g" \
		-e "s|@@LOGDIR@@|/var/log/jabberd|g " \
		-e "s|@@BINDIR@@|${PREFIX}/bin|g " \
		-e "s|@@DBDIR@@|/var/db/jabberd|g " \
		< ${WRKSRC}/etc/${f}.in > ${WRKSRC}/etc/${f}
.endfor
.undef f

	${SED}  \
		-e "s|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g" \
		< ${WRKSRC}/etc/jabberd.cfg.in > ${WRKSRC}/etc/jabberd.cfg

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/jabberd.cfg ${EGDIR}

.for f in ${FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${EGDIR}
.endfor

.include "../../converters/libiconv/buildlink2.mk"
.include "../../databases/db4/buildlink2.mk"
.include "../../databases/openldap/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../security/cyrus-sasl2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
