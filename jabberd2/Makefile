# $NetBSD: Makefile,v 1.17 2003/09/27 10:10:50 xtraeme Exp $
#

DISTNAME=		jabberd-2.0b1
PKGNAME=		${DISTNAME:S/d-2.0b1/d2-2.0beta1/}
CATEGORIES=		chat
MASTER_SITES=		http://www.jabberstudio.org/files/jabberd2/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://jabberd.jabberstudio.org/2/
COMMENT=		Instant messaging server ( version 2 )

CONFLICTS=		jabberd-[0-9]*:../../wip/jabberd

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	JABBERD_USER JABBERD_GROUP \
		JABBERD_AUTH_METHOD JABBERD_STORAGE_METHOD \
		JABBERD_LOGDIR JABBERD_DBDIR JABBERD_PIDDIR

# This specify the actual method which will be used for authenticate
# the users/accounts.
#
# JABBERD_AUTH_METOD has 4 available options:
#
# db (by default)
# mysql (MySQL)
# openldap (OpenLDAP)
# pam (Pluggable Authentication Module)
# pgsql (PostgreSQL)

JABBERD_AUTH_METOD?=		db

.if defined(JABBERD_AUTH_METHOD) && ${JABBERD_AUTH_METHOD} == "db"
CONFIGURE_ARGS+=	--enable-authreg=db
CONFIGURE_ARGS+=	--with-berkeley-db=${BUILDLINK_PREFIX.db4}
.include "../../databases/db4/buildlink2.mk"
.elif defined(JABBERD_AUTH_METHOD) && ${JABBERD_AUTH_METHOD} == "openldap"
CONFIGURE_ARGS+=	--enable-authreg=ldap
CONFIGURE_ARGS+=	--with-openldap=${BUILDLINK_PREFIX.openldap}
.include "../../databases/openldap/buildlink2.mk"
.elif defined(JABBERD_AUTH_METHOD) && ${JABBERD_AUTH_METHOD} == "pgsql"
CONFIGURE_ARGS+=	--enable-authreg=pgsql
CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-lib}
.include "../../databases/postgresql-lib/buildlink2.mk"
.elif defined(JABBERD_AUTH_METHOD) && ${JABBERD_AUTH_METHOD} == "mysql"
CONFIGURE_ARGS+=	--enable-authreg=mysql
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-server}
.include "../../databases/mysql-client/buildlink2.mk"
.elif defined(JABBERD_AUTH_METHOD) && ${JABBERD_AUTH_METHOD} == "pam"
CONFIGURE_ARGS+=	--enable-authreg=pam
CONFIGURE_ARGS+=	--with-pam=${BUILDLINK_PREFIX.PAM}
.include "../../security/PAM/buildlink2.mk"
.endif

# This specify the actual method which will be used to store the accounts
# and related information.
#
# JABBERD_STORAGE_METHOD has 3 available options:
#
# db (by default)
# mysql (MySQL)
# pgsql (PostgreSQL)

JABBERD_STORAGE_METHOD?=	db

.if defined(JABBERD_STORAGE_METHOD) && ${JABBERD_STORAGE_METHOD} == "db"
CONFIGURE_ARGS+=	--enable-storage=db
CONFIGURE_ARGS+=	--with-berkeley-db=${BUILDLINK_PREFIX.db4}
.include "../../databases/db4/buildlink2.mk"
.elif defined(JABBERD_STORAGE_METHOD) && ${JABBERD_STORAGE_METHOD} == "mysql"
CONFIGURE_ARGS+=	--enable-storage=mysql
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-server}
.include "../../databases/mysql-client/buildlink2.mk"
.elif defined(JABBERD_STORAGE_METHOD) && ${JABBERD_STORAGE_METHOD} == "pgsql"
CONFIGURE_ARGS+=	--enable-storage=pgsql
CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-lib}
.include "../../databases/postgresql-lib/buildlink2.mk"
.endif

RCD_SCRIPTS=		jabberd
PKG_SYSCONFSUBDIR=	jabberd

JABBERD_USER?=		jabberd
JABBERD_GROUP?=		jabberd
PKG_GROUPS=             ${JABBERD_GROUP}
PKG_USERS=              ${JABBERD_USER}:${JABBERD_GROUP}::Jabberd\\ user
EGDIR=			${PREFIX}/share/examples/jabberd
SUPPORT_FILES=          ${EGDIR}/jabberd.cfg ${PKG_SYSCONFDIR}/jabberd.cfg

FILES=			c2s.xml resolver.xml router.xml s2s.xml sm.xml
.for f in ${FILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.undef f

# Directory to store the log files
JABBERD_LOGDIR?=	/var/log/jabberd

# Directory to store the database files
JABBERD_DBDIR?=		/var/db/jabberd

# Directory to store the pid files
JABBERD_PIDDIR?=	/var/run/jabberd

.for f in ${JABBERD_LOGDIR} ${JABBERD_DBDIR} ${JABBERD_PIDDIR}
OWN_DIRS_PERMS+=	${f} ${JABBERD_USER} ${JABBERD_GROUP} 750
.endfor
.undef f

post-extract:

.for f in jabberd.cfg ${FILES}
	${MV} ${WRKSRC}/etc/${f}.dist.in ${WRKSRC}/etc/${f}.in
.endfor
.undef f

pre-configure:

.for f in ${FILES}
	${SED}  \
		-e "s|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g" \
		-e "s|@@PIDDIR@@|${JABBERD_PIDDIR}|g" \
		-e "s|@@LOGDIR@@|${JABBERD_LOGDIR}|g " \
		-e "s|@@BINDIR@@|${PREFIX}/bin|g " \
		-e "s|@@DBDIR@@|${JABBERD_DBDIR}|g " \
		${WRKSRC}/etc/${f}.in > ${WRKSRC}/etc/${f}
.endfor
.undef f

	${SED}  \
		-e "s|@@PKG_SYSCONFDIR@@|${PKG_SYSCONFDIR}|g" \
		-e "s|@@BINDIR@@|${PREFIX}/bin|g " \
		${WRKSRC}/etc/jabberd.cfg.in > ${WRKSRC}/etc/jabberd.cfg

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
.for f in jabberd.cfg ${FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${EGDIR}
.endfor

.include "../../converters/libiconv/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
