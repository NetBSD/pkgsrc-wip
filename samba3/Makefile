# $NetBSD: Makefile,v 1.2 2003/08/01 21:15:26 jeremy-c-reed Exp $

DISTNAME=		samba-3.0.0beta3
WRKSRC?=		${WRKDIR}/${DISTNAME}/source
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.samba.org/pub/samba/beta/ \
			ftp://ring.asahi-net.or.jp/pub/net/samba/beta/ \
			ftp://samba.anu.edu.au/pub/samba/beta/ \
			ftp://ftp.sunet.se/pub/unix/utilities/samba/beta/
COUNTRY_MIRRORS=	au1 ca fi fr de it pl ru sg se us1 us6
.for COUNTRY in ${COUNTRY_MIRRORS}
MASTER_SITES+=		ftp://${COUNTRY}.samba.org/pub/samba/beta/
.endfor
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.samba.org/
COMMENT=		SMB/CIFS protocol server suite for UNIX (v3)

CONFLICTS=		samba-[0-9]*
CONFLICTS+=		samba20-[0-9]*

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	samba

VARDIR?=		${VARBASE:U/var}
SAMBA_ETCDIR?=		${PKG_SYSCONFDIR}
SAMBA_DATADIR?=		${PREFIX}/share
SAMBA_LIBDIR?=		${PREFIX}/lib/samba
SAMBA_LOCKDIR?=		${VARDIR}/db/samba
SAMBA_LOGDIR?=		${VARDIR}/log
SAMBA_PIDDIR?=		${VARDIR}/run
SAMBA_PRIVATE?=		${SAMBA_ETCDIR}/private

CONFIGURE_ARGS+=	--localstatedir=${VARDIR}
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--with-configdir=${SAMBA_ETCDIR}
# XXX not used???
#CONFIGURE_ARGS+=	--with-codepagedir=${SAMBA_DATADIR}/samba/codepages
CONFIGURE_ARGS+=	--datadir=${SAMBA_DATADIR}
CONFIGURE_ARGS+=	--libdir=${SAMBA_LIBDIR}
CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR}
CONFIGURE_ARGS+=	--with-logfilebase=${SAMBA_LOGDIR}
CONFIGURE_ARGS+=	--with-piddir=${SAMBA_PIDDIR}
CONFIGURE_ARGS+=	--with-privatedir=${SAMBA_PRIVATE}
CONFIGURE_ARGS+=	--with-swatdir=${SAMBA_DATADIR}/samba/swat

# do I need this?
#CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no

USE_GNU_READLINE=	# uses rl_event_hook interface to GNU readline
CONFIGURE_ARGS+=	--with-readline

# check this:
CONFIGURE_ARGS+=	--without-winbind

# XXX maybe an option to use popt package instead?
CONFIGURE_ARGS+=        --with-included-popt

# The following are Linux-only options.
CONFIGURE_ARGS+=	--without-smbwrapper
CONFIGURE_ARGS+=	--without-smbmount

FILES_SUBST=		SAMBA_PRIVATE=${SAMBA_PRIVATE}
FILES_SUBST+=		SAMBA_LOCKDIR=${SAMBA_LOCKDIR}
FILES_SUBST+=		SAMBA_LOGDIR=${SAMBA_LOGDIR}
FILES_SUBST+=		SAMBA_ETCDIR=${SAMBA_ETCDIR}

#REPLACE_PERL+=		script/findsmb.in

.if defined(USE_CUPS) && (${USE_CUPS} == "YES")
.include "../../print/cups/buildlink2.mk"
BUILD_DEFS+=		USE_CUPS
CONFIGURE_ARGS+=	--enable-cups
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

.if defined(USE_PAM)
.include "../../security/PAM/buildlink2.mk"
BUILD_DEFS+=		USE_PAM
CONFIGURE_ARGS+=	--with-pam
# Also build PAM module for authenticating against passdb backends
# XXX maybe check if this is Linux only?
CONFIGURE_ARGS+=	--with-pam_smbpass
.else
CONFIGURE_ARGS+=	--without-pam
CONFIGURE_ARGS+=	--without-pam_smbpass
.endif

# --with-ldapsam is now used to provided backward compatible
#    parameters for LDAP enabled Samba 2.2 servers
.if defined(SAMBA_USE_LDAP) && ${SAMBA_USE_LDAP} == "YES"
.include "../../databases/openldap/buildlink2.mk"
BUILD_DEFS+=		SAMBA_USE_LDAP
CONFIGURE_ARGS+=	--with-ldapsam
PLIST_SUBST+=		SAMBA_LDAP=""
.else
CONFIGURE_ARGS+=	--without-ldapsam
PLIST_SUBST+=		SAMBA_LDAP="@comment "
MESSAGE_SRC=		${.CURDIR}/MESSAGE.smbpasswd
SMBPASSWD_FILE=		/dev/null ${SAMBA_PRIVATE}/smbpasswd		\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endif

SAMBA_USE_ACTIVE_DIRECTORY?=	YES
.if defined(SAMBA_USE_ACTIVE_DIRECTORY) && ${SAMBA_USE_ACTIVE_DIRECTORY} == "YES"
.include "../../databases/openldap/buildlink2.mk"
.include "../../wip/mit-krb5/buildlink2.mk"
BUILD_DEFS+=		SAMBA_USE_ACTIVE_DIRECTORY
CONFIGURE_ARGS+=	--with-ads
CONFIGURE_ARGS+=	--with-ldap
CONFIGURE_ARGS+=	--with-krb5=${BUILDLINK_PREFIX.mit-krb5}
.else
CONFIGURE_ARGS+=	--without-ads
CONFIGURE_ARGS+=	--without-ldap
.endif

MESSAGE_SUBST+=		SAMBA_PRIVATE=${SAMBA_PRIVATE}
MESSAGE_SUBST+=		ROOT_GROUP=${ROOT_GROUP}
MESSAGE_SUBST+=		ROOT_USER=${ROOT_USER}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EXAMPLESDIR=		${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=		${EXAMPLESDIR}/smb.conf.default ${SAMBA_ETCDIR}/smb.conf
SUPPORT_FILES_PERMS=	${SMBPASSWD_FILE}
RCD_SCRIPTS=		samba nmbd smbd
OWN_DIRS=		${SAMBA_ETCDIR} ${SAMBA_LOCKDIR}
OWN_DIRS_PERMS=		${SAMBA_PRIVATE} ${ROOT_USER} ${ROOT_GROUP} 0600

# Remove irrelevant files for this package.
post-extract:
	${FIND} ${WRKDIR}/${DISTNAME} -name ".cvsignore" -print |	\
		${XARGS} ${RM} -f

post-install:
	# Install Samba documentation.
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKDIR}/${DISTNAME}/docs;					\
	for file in textdocs/* Registry/*.reg; do			\
		${INSTALL_DATA} $$file ${DOCDIR};			\
	done

	# Install Samba examples.
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${CP} -R ${WRKDIR}/${DISTNAME}/examples/* ${EXAMPLESDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/script/mknissmbpasswd.sh		\
		${EXAMPLESDIR}/misc
	${INSTALL_SCRIPT} ${WRKSRC}/script/mksmbpasswd.sh		\
		${PREFIX}/sbin/mksmbpasswd
	${INSTALL_SCRIPT} ${WRKSRC}/script/updatesmbpasswd.sh		\
		${PREFIX}/sbin/updatesmbpasswd
# XXX don't change user, because when doing as regular user can't remove
	${CHMOD} -R go-w ${EXAMPLESDIR}

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
