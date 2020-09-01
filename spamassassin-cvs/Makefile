# $NetBSD: Makefile,v 1.20 2014/10/09 14:06:30 thomasklausner Exp $

DISTNAME=	Mail-SpamAssassin-${_SA_CVS_VER}
PKGNAME=	spamassassin-cvs-${_SA_CVS_DATE}
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://www.spamassassin.org/devel/		\
		http://eu.spamassassin.org/devel/		\
		http://au.spamassassin.org/devel/

MAINTAINER=	tom@replic8.net
HOMEPAGE=	https://spamassassin.apache.org/
COMMENT=	Mail filter to identify spam (CVS snapshot)
LICENSE=	apache-2.0

DEPENDS+=	p5-Net-DNS>=0.29:../../net/p5-Net-DNS
DEPENDS+=	p5-HTML-Parser>=3.29:../../www/p5-HTML-Parser
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-MIME-Base64>=2.11:../../converters/p5-MIME-Base64
#DEPENDS+=	p5-DB_File-[0-9]*:../../databases/p5-DB_File

CONFLICTS=	p5-Mail-SpamAssassin-[1-9]* \
		spamassassin-[1-9]*


EXTRACT_SUFX?=	.tar.bz2
NO_CHECKSUM=	YES

.include "../../mk/bsd.prefs.mk"

# which version of SA is current in CVS
_SA_CVS_VER?=	3.000000-cvs
_SA_CVS_DATE!=	${DATE} +%Y%m%d

WRKSRC=		${WRKDIR}/${DISTNAME:S/-cvs//}

PERL5_REQD+=	5.6.1	# MakeMaker >= 5.45 needed, >= 6.16 recommended

PKG_SYSCONFSUBDIR=	spamassassin

# Set contact address (e-mail, URL, ...) for use in spam report messages
# See "perldoc Mail::SpamAssassin::Conf" for option "report_contact"
SPAMASSASSIN_CONTACT_ADDRESS?=		'postmaster'

# Use "NO" to turn off warnings and taint checks in spamd/spamassassin
SPAMASSASSIN_PERL_WARNINGS?=		YES
SPAMASSASSIN_PERL_TAINT_CHECKS?=	YES

# Enable test for Razor/Pyzor during 'make test'?
SPAMASSASSIN_NET_TESTS?=		NO

# Use "NO" to disable OpenSSL support
SPAMASSASSIN_USE_SSL?=			YES

# Enable MySQL support using p5-DBI/DBD?
SPAMASSASSIN_USE_MYSQL?=		NO

# Enable razor-agents support?
SPAMASSASSIN_USE_RAZOR?=		YES

# Enable pyzor support?
SPAMASSASSIN_USE_PYZOR?=		NO

.if !empty(SPAMASSASSIN_USE_SSL:M[yY][eE][sS])
.  include "../../security/openssl/buildlink3.mk"
DEPENDS+=		p5-IO-Socket-SSL>=0.92:../../security/p5-IO-Socket-SSL
CONFIGURE_ARGS+=	--enable-ssl
MAKE_PARAMS=		ENABLE_SSL=yes
SA_SSLCERTS=		${SSLCERTS}
.else
CONFIGURE_ARGS+=	--disable-ssl
MAKE_PARAMS=		ENABLE_SSL=no
SA_SSLCERTS=		'$$LOCAL_RULES_DIR/certs'
.endif

.if !empty(SPAMASSASSIN_USE_MYSQL:M[yY][eE][sS])
.include "../../databases/p5-DBI/buildlink3.mk"
DEPENDS+=		p5-DBI>=1.37:../../databases/p5-DBI
DEPENDS+=		p5-DBD-mysql>=2.1017:../../databases/p5-DBD-mysql
.endif

.if !empty(SPAMASSASSIN_USE_RAZOR:M[yY][eE][sS])
DEPENDS+=		p5-razor-agents>=2.36:../../mail/p5-razor-agents
SPAMASSASSIN_NET_TESTS?=	YES
.endif

.if !empty(SPAMASSASSIN_USE_PYZOR:M[yY][eE][sS])
#DEPENDS+=		pyzor>=0.4.0:../../mail/pyzor
DEPENDS+=		pyzor>=0.4.0:../../wip/pyzor
SPAMASSASSIN_NET_TESTS?=	YES
.endif

BUILD_DEFS+=		SPAMASSASSIN_USE_SSL
BUILD_DEFS+=		SPAMASSASSIN_USE_MYSQL
BUILD_DEFS+=		SPAMASSASSIN_USE_RAZOR
BUILD_DEFS+=		SPAMASSASSIN_USE_PYZOR
BUILD_DEFS+=		SPAMASSASSIN_CONTACT_ADDRESS
BUILD_DEFS+=		SPAMASSASSIN_PERL_WARNINGS
BUILD_DEFS+=		SPAMASSASSIN_PERL_TAINT_CHECKS

PLIST_ADD=		${WRKSRC}/.PLIST_ADD
PLIST_SRC=		${PKGDIR}/PLIST ${PLIST_ADD}
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/SpamAssassin/.packlist

#GNU_CONFIGURE=		YES
CONFIGURE_DIRS=		${WRKSRC}/spamd
PERL5_CONFIGURE=	NO # we need the default "do-configure" target
PERL5_CONFIGURE_DIRS=	${WRKSRC}

MAKE_PARAMS+=		SYSCONFDIR="${PKG_SYSCONFDIR}"
MAKE_PARAMS+=		LOCALRULESDIR="${PKG_SYSCONFDIR}"
MAKE_PARAMS+=		DEFRULESDIR="${RULESDIR}"
MAKE_PARAMS+=		RUN_NET_TESTS="${SPAMASSASSIN_NET_TESTS}"
MAKE_PARAMS+=		PERL_WARN="${SPAMASSASSIN_PERL_WARNINGS}"
MAKE_PARAMS+=		PERL_TAINT="${SPAMASSASSIN_PERL_TAINT_CHECKS}"

RCD_SCRIPTS=		spamd
RCD_SCRIPT_SRC.spamd=	${WRKSRC}/spamd/netbsd-rc-script.sh

EGDIR=			${PREFIX}/share/examples/spamassassin
DOCDIR=			${PREFIX}/share/doc/spamassassin
DOC_SUBDIR=		${DOCDIR:S,^${PREFIX}/,,}
HTMLDIR=		${PREFIX}/share/doc/html/spamassassin
RULESDIR=		${PREFIX}/share/spamassassin
RULE_SUBDIR=		${RULESDIR:S,^${PREFIX}/,,}

CONF_FILES+=		${EGDIR}/local.cf  ${PKG_SYSCONFDIR}/local.cf	\
			${RULESDIR}/user_prefs.template			\
			${PKG_SYSCONFDIR}/user_prefs.template
SUPPORT_FILES_PERMS+=	${EGDIR}/netbsd_lists.cf			\
			${PKG_SYSCONFDIR}/netbsd_lists.cf ${SHAREOWN}	\
			${SHAREGRP} ${SHAREMODE}

OWN_DIRS+=		${EGDIR} ${DOCDIR} ${DOCDIR}/spamd ${HTMLDIR}

SUBST_CLASSES+=		sa1 sa2 sa3

SUBST_STAGE.sa1=	post-patch
SUBST_FILES.sa1=	Makefile.PL
SUBST_SED.sa1=		-e s!@SA_CONTACT_ADDRESS@!${SPAMASSASSIN_CONTACT_ADDRESS}!

SUBST_STAGE.sa2=	post-patch
SUBST_FILES.sa2=	README spamd/spamd.raw
SUBST_VARS.sa2=		PREFIX PKG_SYSCONFDIR SA_SSLCERTS

SUBST_STAGE.sa3=	post-patch
SUBST_FILES.sa3=	INSTALL USAGE lib/Mail/SpamAssassin/Conf.pm	\
			spamd/README spamd/README.vpopmail	\
			sql/README sql/README.awl sql/README.bayes
SUBST_SED.sa3=		-e s!/usr/share!${PREFIX}/share!g		\
			-e s!/usr/bin!${PREFIX}/bin!g			\
			-e s!/usr/lib!${PREFIX}/lib!g			\
			-e s!/etc/mail/spamassassin!${PKG_SYSCONFDIR}!g

.if ${OPSYS} == "NetBSD"
#  the 'spamd' RCD_SCRIPT behaves differently if we run NetBSD 1.6 or later
.  if ${OS_VERSION:M1.[0-5]*}
INTERPRETER_SUPPORT=	NO
.  else
INTERPRETER_SUPPORT=	YES
.  endif
.endif

# These values are substituted into netbsd-rc-script.sh.
FILES_SUBST+=		INTERPRETER_SUPPORT=${INTERPRETER_SUPPORT:Q}
FILES_SUBST+=		OPSYS=${OPSYS}

pre-configure: perl5-configure

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print -o			\
		-name "*.subst.sav" -print | ${XARGS} ${RM} -f

post-install:
	@${TEST} -r ${PLIST_ADD} && ${RM} ${PLIST_ADD} ; :
	@ # ninja image is in the static PLIST
	@${INSTALL_DATA} ${WRKSRC}/ninjabutton.png ${HTMLDIR}/
.for f in COPYRIGHT INSTALL LICENSE README TRADEMARK USAGE		\
		CREDITS PACKAGING STATUS BUGS Changes			\
		sample-nonspam.txt sample-spam.txt spamd/README		\
		spamd/README.vpopmail
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}/${f}
	@${ECHO} "${DOC_SUBDIR}/${f}" >> ${PLIST_ADD}
.endfor
.for f in STATISTICS.txt STATISTICS-set1.txt STATISTICS-set2.txt	\
		STATISTICS-set3.txt
	@${INSTALL_DATA} ${WRKSRC}/rules/${f} ${DOCDIR}/
	@${ECHO} "${DOC_SUBDIR}/${f}" >> ${PLIST_ADD}
.endfor
.for DIR in masses sql ldap tools
	@cd ${WRKSRC};							\
	for d in `${FIND} ${DIR} -type d -print`; do			\
		${INSTALL_DATA_DIR} ${DOCDIR}/$$d;			\
	done;								\
	for f in `${FIND} ${DIR} -type f -print`; do			\
		if ${TEST} -f $$f; then					\
			: ; 						\
		else							\
			continue;					\
		fi;							\
		if ${TEST} -x $$f ; then				\
			${SED} -e "1s,#!.*/bin/perl,#!${PERL5}," < $$f	\
				> $${f}.fixed &&			\
			${MV} $${f}.fixed $$f &&			\
			${CHMOD} +x $$f &&				\
			${INSTALL_SCRIPT} $$f ${DOCDIR}/$$f;		\
		else							\
			${INSTALL_DATA} $$f ${DOCDIR}/$$f;		\
		fi;							\
		${ECHO} "${DOC_SUBDIR}/$$f" >> ${PLIST_ADD};		\
	done;								\
	 | ${SORT} -r >> ${PLIST_ADD};
.endfor
	@cd ${WRKSRC}/rules;						\
	for f in [0-9]*.cf; do						\
		${ECHO} "${RULE_SUBDIR}/$$f" >> ${PLIST_ADD};		\
	done
	@# examples are in the static PLIST
	@${INSTALL_DATA} ${WRKSRC}/procmailrc.example ${EGDIR}/
	@${INSTALL_DATA} ${WRKSRC}/rules/local.cf ${EGDIR}/
	@${INSTALL_DATA} ${FILESDIR}/netbsd_lists.cf ${EGDIR}/
	@${CHOWN} ${SHAREOWN} ${RULESDIR}/*
	@${CHGRP} ${SHAREGRP} ${RULESDIR}/*
	@${CHMOD} a=r ${RULESDIR}/*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
