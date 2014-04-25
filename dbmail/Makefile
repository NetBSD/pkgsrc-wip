# $NetBSD: Makefile,v 1.8 2014/04/25 09:50:24 fhajny Exp $

DISTNAME=	dbmail-3.1.13
CATEGORIES=	mail
MASTER_SITES=	http://www.dbmail.org/download/3.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dbmail.org/
COMMENT=	Store and retrieve mail messages in a database
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_TOOLS+=		gmake perl pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log
CONFIGURE_ARGS+=	--with-pkglibdir=${PREFIX}/lib/dbmail
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/run
CONFIGURE_ARGS+=	--enable-manpages
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-zdb=${BUILDLINK_PREFIX.libzdb}

CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

BUILD_DEFS+=		VARBASE

EGDIR=			${PREFIX}/share/examples/dbmail
CONF_FILES_PERMS+=	${EGDIR}/dbmail.conf ${PKG_SYSCONFDIR}/dbmail.conf \
			  ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0640
RCD_SCRIPTS=		dbmail dbmailimapd dbmaillmtpd dbmailpop3d
DATADIR=		${PREFIX}/share/dbmail
DOCSDIR=		${PREFIX}/share/doc/dbmail
DOCS=			AUTHORS BUGS COPYING INSTALL NEWS README
DOCS+=			THANKS UPGRADING
DOCS+=			doc/README.smtp doc/README.solaris doc/README.qmail
DOCS+=			doc/README.usermap doc/README.sieve doc/README.postfix
DOCS+=			doc/README.exim doc/README.http doc/README.aliases
DOCS+=			doc/README.filters doc/README.ldap

MESSAGE_SUBST+=		DOCSDIR=${DOCSDIR}
MESSAGE_SUBST+=		DATADIR=${DATADIR}
REPLACE_PERL+=		man/fixsp.pl

INSTALLATION_DIRS=	lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin ${DOCSDIR} ${EGDIR}
INSTALLATION_DIRS+=	${DATADIR}/sql/mysql ${DATADIR}/sql/postgresql ${DATADIR}/sql/sqlite

post-install:
	${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${DESTDIR}${EGDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/sql/mysql/* ${DESTDIR}${DATADIR}/sql/mysql
	${INSTALL_DATA} ${WRKSRC}/sql/postgresql/* ${DESTDIR}${DATADIR}/sql/postgresql
	${INSTALL_DATA} ${WRKSRC}/sql/sqlite/* ${DESTDIR}${DATADIR}/sql/sqlite

.include "options.mk"

.include "../../databases/openldap-client/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gmime+=	gmime>=2.2.10
.include "../../mail/gmime24/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../wip/libzdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
