# $NetBSD: Makefile,v 1.13 2004/08/05 20:48:54 adrian_p Exp $

.include "../../wip/sendmail813/Makefile.common"

PKGNAME=	sendmail-${DIST_VERS}
COMMENT=	The well known Mail Transport Agent

CONFLICTS+=	postfix-[0-9]* fastforward-[0-9]*

MESSAGE_SRC=	${WRKDIR}/.MESSAGE_SRC
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

.if ${OPSYS} != "Linux"
PLIST_SUBST+=  CAT1=0
PLIST_SUBST+=  CAT5=0
PLIST_SUBST+=  CAT8=0
.else
PLIST_SUBST+=  CAT1=1
PLIST_SUBST+=  CAT5=5
PLIST_SUBST+=  CAT8=8
.endif

SUBST_CLASSES=		paths perl
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	${WRKDIR}/mailer.conf
SUBST_SED.paths=	-e "s|@@PREFIX@@|${PREFIX}|g"
SUBST_MESSAGE.paths=	Fixing paths.

SUBST_STAGE.perl=	pre-build
SUBST_FILES.perl=	contrib/socketmapClient.pl contrib/socketmapServer.pl
SUBST_SED.perl=		-e "s|/usr/bin/perl|${PREFIX}/bin/perl|g"
SUBST_MESSAGE.perl=	Fixing perl path.

.if ${OPSYS} == "SunOS"
USE_DB2?=	YES
.else
USE_DB2?=	NO
.endif
.if defined(USE_DB4) && ${USE_DB4} == YES
.include "../../databases/db4/buildlink3.mk"
.elif ${USE_DB2} == YES
.include "../../databases/db/buildlink3.mk"
.endif

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
.include "../../databases/openldap/buildlink3.mk"
.endif

.if defined(USE_SASL2) && ${USE_SASL2} == YES
.include "../../security/cyrus-sasl2/buildlink3.mk"
.elif defined(USE_SASL) && ${USE_SASL} == YES
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if defined(USE_STARTTLS) && ${USE_STARTTLS} == YES
.include "../../security/openssl/buildlink3.mk"
.endif

USE_TCPWRAPPERS?=	YES
.if ${USE_TCPWRAPPERS} == YES
.include "../../security/tcp_wrappers/buildlink3.mk"
.endif

post-patch: make-sendmail-siteconfig
.if ${USE_TCPWRAPPERS} == YES
	@${CAT} ${FILESDIR}/site.config.m4-tcpwrappers >>${SITECONFIG}
.endif
.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
	@${CAT} ${FILESDIR}/site.config.m4-ldap >>${SITECONFIG}
.endif
.if defined(USE_DB4) && ${USE_DB4} == YES
	@${CAT} ${FILESDIR}/site.config.m4-db4 >>${SITECONFIG}
.elif ${USE_DB2} == YES
	@${CAT} ${FILESDIR}/site.config.m4-db2 >>${SITECONFIG}
.endif
.if defined(USE_STARTTLS) && ${USE_STARTTLS} == YES
	@${CAT} ${FILESDIR}/site.config.m4-starttls >>${SITECONFIG}
.endif
.if defined(USE_SASL2) && ${USE_SASL2} == YES
	@${CAT} ${FILESDIR}/site.config.m4-sasl2 >>${SITECONFIG}
.elif defined(USE_SASL) && ${USE_SASL} == YES
	@${CAT} ${FILESDIR}/site.config.m4-sasl >>${SITECONFIG}
.endif
.if defined(USE_SOCKETMAP) && ${USE_SOCKETMAP} == YES
	@${CAT} ${FILESDIR}/site.config.m4-socketmap >>${SITECONFIG}
	USE_PERL5=	YES
.endif

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build)
	@${CP} ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf

post-build:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@${CP} ${PKGDIR}/MESSAGE ${MESSAGE_SRC}

.if ${USE_DB2} == YES
	@${ECHO} "" >>${MESSAGE_SRC}
	@${ECHO} "If you are upgrading from \"sendmail\" 8.8.x don't forget to rebuild all" >>${MESSAGE_SRC}
	@${ECHO} "databases with \"${PREFIX}/bin/newaliases\" and \"${PREFIX}/sbin/makemap\"." >>${MESSAGE_SRC}
	@${ECHO} >>${PLIST_SRC} "@exec mv -f /usr/sbin/makemap /usr/sbin/makemap.8.8 || true"
	@${ECHO} >>${PLIST_SRC} "@unexec mv -f /usr/sbin/makemap.8.8 /usr/sbin/makemap || true"
.endif

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/sendmail

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sendmail
	${INSTALL_DATA_DIR} ${PREFIX}/share/sendmail
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sendmail
	${INSTALL_DATA} ${WRKDIR}/mailer.conf \
		${PREFIX}/share/examples/sendmail/
	cd ${WRKSRC}/cf && ${PAX} -rw -pp -pm . ${PREFIX}/share/sendmail
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/sendmail

.if ${USE_DB2} == YES
	@${MV} -f /usr/sbin/makemap /usr/sbin/makemap.8.8 || ${TRUE}
.endif

	${INSTALL_DATA} ${WRKSRC}/obj.`${UNAME} -srm | ${TR} \  . | ${TR} \/ - | ${SED} s/sun4./sun4/`/libsm/libsm.a \
		${PREFIX}/lib

	${INSTALL_DATA} \
		${WRKSRC}/obj.`${UNAME} -srm | ${TR} \  . | ${TR} \/ - | ${SED} s/sun4./sun4/`/libsmutil/libsmutil.a \
		${PREFIX}/lib

	${INSTALL_SCRIPT} ${WRKSRC}/contrib/socketmapClient.pl \
		${PREFIX}/share/examples/sendmail
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/socketmapServer.pl \
		${PREFIX}/share/examples/sendmail

	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${PREFIX}/share/doc/sendmail
	${INSTALL_DATA} ${WRKSRC}/cf/README ${PREFIX}/share/doc/sendmail
	${INSTALL_DATA} ${WRKSRC}/sendmail/SECURITY ${PREFIX}/share/doc/sendmail
	${INSTALL_DATA} ${WRKSRC}/doc/op/op.me ${PREFIX}/share/doc/sendmail
	${INSTALL_DATA} ${WRKSRC}/doc/op/op.ps ${PREFIX}/share/doc/sendmail

USE_PKGINSTALL=	yes
PKG_GROUPS=	smmsp
PKG_USERS=	smmsp:smmsp::Sendmail\\ Message\\ Submission\\ Program

.include "../../mk/bsd.pkg.mk"

# has to be below include for bsd.pkg.mk, else substition fails
OBJDIR!=	${ECHO} obj.`${UNAME} -srm | ${TR} \  . | ${TR} \/ -`
